#include "btpclient.hpp"
#include "client.hpp"
#include "gateway.hpp"
#include <functional>

void btpclient::start(io_context& io, std::string addr, std::string port)
{
  using namespace std::placeholders;
  _client =  std::make_shared<client>();
  _gateway =  std::make_shared<gateway>();
  _gateway->start(std::bind(&client::send, _client, _1 ) );
  _client->start(io, addr, port, std::bind(&gateway::receive, _gateway, _1 ) );
}

void btpclient::get_names( std::function<void(std::vector<std::string>)> handler)
{
  auto req = std::make_unique<wamba::btp::request::get_names>();
  req->limit = 10000000;
  (*_gateway)->get_names(
    std::move(req),
    [handler]( wamba::btp::response::get_names::ptr res)
    {
      std::vector<std::string> names;
      names.resize(res->names_ts.size());
      std::transform(
        res->names_ts.begin(),
        res->names_ts.end(),
        names.begin(),
        []( wamba::btp::response::get_names::name_ts& pair )
        { return std::move(pair.first); }
      );
      handler( std::move(names) );
    });
}

void btpclient::get( const std::string& name, std::function<void(aggregated_list&&)> handler )
{
  auto req = std::make_unique<wamba::btp::request::get>();
  req->name = name;
  (*_gateway)->get(
    std::move(req),
    [handler]( wamba::btp::response::get::ptr res)
    {
      if ( res )
        handler( std::move(res->counters) );
      else
        handler( aggregated_list() );
    }
  );
}

void btpclient::merge( const std::string& name, aggregated_list&& aglst, std::function<void()> handler )
{
  auto req = std::make_unique<wamba::btp::request::merge>();
  req->name = name;
  req->counters = std::move(aglst);
  (*_gateway)->merge( std::move(req), [handler]( wamba::btp::response::merge::ptr ){ handler(); } );
}

void btpclient::compact(std::function<void()> handler)
{
  (*_gateway)->compact(
    std::make_unique<wamba::btp::request::compact>(),
    [handler]( wamba::btp::response::compact::ptr ){ handler();}
  );
}
