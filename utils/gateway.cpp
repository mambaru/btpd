#include "gateway.hpp"
#include <wjrpc/engine.hpp>
#include <ag/gateway/ag_gateway.hpp>

using namespace wamba::btp;

class gateway::impl
  : public wjrpc::engine< wjrpc::handler<
            ag::gateway::interface_< ag::gateway::method_list >  
    > > 
{
};

void gateway::start(handler h)
{
  using namespace std::placeholders;
  impl::options_type opt;
  _impl = std::make_shared<impl>();
  _impl->start(opt, 1);
  _impl->reg_io(41, std::bind(h, _1) );
}

std::shared_ptr<wamba::btp::ibtp> gateway::operator -> ()
{
  if ( auto phandler = _impl->find(41) )
  {
    return std::static_pointer_cast<wamba::btp::ibtp>(phandler);
  }
  return nullptr;
}

void gateway::receive( data_ptr d )
{
  _impl->perform_io( std::move(d), 41, nullptr);
}

