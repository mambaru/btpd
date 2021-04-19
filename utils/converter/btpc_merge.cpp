#include <iostream>
#include <iomanip>
#include <wlog/init.hpp>
#include <wlog/logging.hpp>
#include "btpclient.hpp"

using namespace std::placeholders;
void process_names(std::vector<std::string> names);
void query_data( size_t pos, bool compact = true );
void process_data( size_t pos, btpclient::aggregated_list&& );
void show_stat();

boost::asio::io_context io_context;
btpclient from;
btpclient to;
size_t max_lag = 0;
size_t min_points =0;
std::vector<std::string> all_names;


void process_names(std::vector<std::string> names)
{
  WLOG_MESSAGE("Получено имен: "  << names.size() )
  all_names.swap(names);
  query_data(0);
}

void query_data( size_t pos, bool compact )
{

  if ( compact && ( /*(pos % (all_names.size()/10) == 0) ||*/ (pos >= all_names.size())) )
  {
    WLOG_MESSAGE( std::endl )
    WLOG_BEGIN("Сжатие базы на " << (pos * 100)  / all_names.size()  << "%");
    to.compact([pos](){
      WLOG_END("Сжатие базы.")
      //WLOG_END("Сжатие базы. Спим 60 секунд")
      //sleep(60);
      query_data(pos, false);
    });
    return;
  }

  if ( pos >= all_names.size() )
  {
    WLOG_MESSAGE( std::endl )
    WLOG_MESSAGE("Все данные обработанны: " << all_names.size() << " графиков" )
    io_context.stop();
    return;
  }

  from.get(all_names[pos], [pos](btpclient::aggregated_list&& agl)
  {
    process_data(pos, std::move(agl) );
  });
}

void process_data( size_t pos, btpclient::aggregated_list&& agl )
{
  std::string logname = all_names[pos];
  logname.resize(70, ' ');
  if ( all_names[pos].size() > 70 )
  {
    logname.resize(67);
    logname+="...";
  }
  WLOG_PROGRESS( std::setw(7) << (double(pos) * 100.0)  / double(all_names.size()) << "% " << logname << ": "  << agl.size() << "      " )
  /*if ( !agl.empty()  )
  {*/
    to.merge(all_names[pos], std::move(agl), [pos](){
      query_data(pos+1);
    });
  /*}
  else
    query_data(pos+1);*/
}

int main(int argc, char* argv[])
{

  if ( argc < 5 )
  {
    std::cout << "Программа переноса данных из хранилища версии 0.5 в хранилище версии 0.7" << std::endl;
    std::cout << "Usage: " << argv[0] << " from-addr from-port to-addr to-port [max-lag(=0) min-points(=0)]" << std::endl;
    std::cout << "\tmax-lag максимально допустимый сдвиг первой точки в секундах от текущего времени" << std::endl;
    std::cout << "\tmin-points минимальное количество точек на графике.  " << std::endl;
    std::cout << "\tДанные не переносятся, если не срабатывают ОБА ограничения. 0 - параметр игнорируеться." << std::endl;
    std::cout << "Example: "<< argv[0] << " 127.0.0.1 36000 127.0.0.1 37000 7500 300 - для пятисекундного графика " << std::endl
              << "\tесли меньше 300 точек и отставание примерно ~2 часа половина" << std::endl;
    return -1;
  }

  if (argc > 5 )
    max_lag = size_t(std::atol(argv[5]));
  if (argc > 6 )
    min_points = size_t(std::atol(argv[6]));


  wlog::logger_options opt;
  opt.hide = wlog::hide_flags::date | wlog::hide_flags::name;
  opt.resolution = wlog::resolutions::seconds;
  wlog::init(opt);

  from.start(io_context, argv[1], argv[2]);
  to.start(io_context, argv[3], argv[4]);
  from.get_names( process_names  );

  WLOG_MESSAGE("RUN!")
  io_context.run();
  return 0;
}
