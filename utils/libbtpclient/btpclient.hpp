#pragma once

#include <iow/asio.hpp>
#include <btp/types.hpp>
#include <functional>
#include <vector>
#include <string>
#include <memory>
class client;
class gateway;

class btpclient
{
public:
  typedef boost::asio::io_context io_context;
  typedef wamba::btp::aggregated_list aggregated_list;
  void start(io_context& io, const std::string& addr, const std::string& port);

  void get_names( std::function<void(std::vector<std::string>)> handler);
  void get( const std::string& name, std::function<void(aggregated_list&&)> handler );
  void merge( const std::string& name, aggregated_list&& aglst, std::function<void()> handler );
  void compact(std::function<void()> handler);
private:
  std::shared_ptr<client> _client;
  std::shared_ptr<gateway> _gateway;
};
