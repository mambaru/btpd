#pragma once
#include <iow/ip/tcp/client/client.hpp>
#include <iow/asio.hpp>
#include <memory>

class client
{
  class impl;
public:
  typedef boost::asio::io_context io_context;
  typedef iow::io::data_ptr data_ptr;
  typedef iow::io::data_type data_type;
  typedef std::function<void(data_ptr)> handler;

  void start(io_context& io, std::string addr, std::string port, handler h);
  void send(data_ptr d);
private:
  std::shared_ptr<impl> _impl;
};
