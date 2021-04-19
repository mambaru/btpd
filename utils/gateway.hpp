#pragma once
#include <memory>
#include "ibtp.hpp"

class gateway
{
  class impl;
public:

  //typedef ::iow::asio::io_service io_service;
  typedef ::iow::io::data_ptr data_ptr;
  typedef ::iow::io::data_type data_type;
  typedef std::function<void(data_ptr)> handler;

  void start(handler h);
  void receive( data_ptr d );
  std::shared_ptr<wamba::btp::ibtp> operator -> ();
  
private:
  std::shared_ptr<impl> _impl;
};
