#include "client.hpp"
#include <functional>
#include <iow/ip/tcp/client/client.hpp>

class client::impl
  : public iow::ip::tcp::client::client<>
{
public:
  typedef iow::ip::tcp::client::client<> self;
  explicit impl(io_context& io): self(io) {}
};

void client::start(io_context& io, const std::string& addr, const std::string& port, handler h)
{
  _impl = std::make_shared<impl>(io);
  iow::ip::tcp::client::options opt;
  opt.addr = addr;
  opt.port = port;
  opt.async_connect = false;
  opt.connection.reader.sep = "\r\n";
  opt.connection.writer.sep = "\r\n";
  using namespace std::placeholders;
  opt.connection.input_handler = std::bind(h, _1);
  _impl->connect(opt);
}

void client::send(data_ptr d)
{
  _impl->send( std::move(d) );
}
