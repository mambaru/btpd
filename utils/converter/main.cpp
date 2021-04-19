#include <iostream>
#include <wlog/init.hpp>
#include <wlog/logging.hpp>
#include "btpclient.hpp"

using namespace std::placeholders;
void process_names( std::vector< std::string> names );
void query_data( size_t pos );
void process_data( size_t pos, btpclient::aggregated_list );
void show_stat();

btpclient from;
std::vector< std::string> all_names;
std::map< size_t, size_t, std::greater<size_t> > all_sizes;
size_t all_values = 0;


void process_names( std::vector< std::string> names )
{
  WLOG_MESSAGE("Получено имен: "  << names.size() )
  all_names.swap(names);
  //all_sizes.reserve(all_names.size());
  query_data(0);
}

void query_data( size_t pos )
{
  if ( pos >= all_names.size() )
  {
    WLOG_MESSAGE("Все данные запрошены");
    show_stat();
    return;
  }
  from.get(all_names[pos], std::bind(process_data, pos, _1) );
}

void process_data( size_t pos, btpclient::aggregated_list agl )
{
  WLOG_MESSAGE(  ( double(pos) * 100.0)  / double(all_names.size()) << "% " << all_names[pos] << ": "  << agl.size() )
  ++all_sizes[agl.size()];
  all_values += agl.size();
  query_data(pos+1);
}

void show_stat()
{
    WLOG_MESSAGE("Подсчет статистики для " << all_names.size() << " счетчиков");
    std::multimap< size_t, size_t, std::greater<size_t> > rev_sizes;
    WLOG_MESSAGE( "ТОП10 счетчиков по общему числу хранимых точек: ");
    size_t top10 = 0;
    for (auto p : all_sizes)
    {
      WLOG_MESSAGE( p.first <<" точек у " << p.second << " графиков");
      if ( top10++ > 10 )
        break;
    }

    for (auto p : all_sizes)
      rev_sizes.insert( std::make_pair(p.second, p.first) );

    WLOG_MESSAGE( "ТОП50 счетчиков по числу хранимых (ненулевых) точек: ");
    size_t top50 = 0;
    for (auto p : rev_sizes)
    {
      WLOG_MESSAGE( "Для " << p.first << " счетчиков ненулевых точек = " << p.second  );
      if ( top50++ > 50 )
        break;
    }
    WLOG_MESSAGE("Всего имен " << all_names.size());
    WLOG_MESSAGE("Всего ненулевых значений  " << all_values );
}

int main(int argc, char* argv[])
{

  if ( argc != 5 )
  {
    std::cout << "Программа переноса данных из хранилища версии 0.5 в хранилище версии 0.7" << std::endl;
    std::cout << "Usage: " << argv[0] << " from-addr from-port to-addr to-port" << std::endl;
    return -1;
  }

  wlog::init();
  boost::asio::io_context io_context;

  from.start(io_context, argv[1], argv[2]);
  from.get_names( process_names  );

  /*
  client from_cli;
  gateway from_gtw;
  from_gtw.start(std::bind(&client::send, &from_cli, _1 ) );
  from_cli.start(io_service, argv[1], argv[2], std::bind(&gateway::receive, &from_gtw, _1 ) );

  auto req = std::make_unique<wamba::btp::request::get_names>();
  req->limit = 10000000;
  from_gtw->get_names(
    std::move(req),
    []( wamba::btp::response::get_names::ptr res)
    {
      if ( res!= nullptr )
      {
        std::cout << "RECEIVED! "<< res->names_ts.size() << std::endl;
      }
      else
      {
        std::cout << "RECEIVED! null"<< std::endl;
      }
    });
    */
  /*
  std::string sj = "{sdfsfsdfs}";
  from_cli.send( std::make_unique<client::data_type>(sj.begin(), sj.end()) );
  */

  WLOG_MESSAGE("RUN!")
  io_context.run();
  return 0;
}
