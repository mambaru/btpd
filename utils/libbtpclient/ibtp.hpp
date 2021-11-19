#pragma once

#include <ag/iag.hpp>

struct ibtp: public wamba::btp::ibtp
{
  virtual void multi_push( wrtstat::request::multi_push::ptr, wrtstat::response::multi_push::handler) override {}
  virtual void push( wrtstat::request::push::ptr, wrtstat::response::push::handler) override {}
  virtual void del( wrtstat::request::del::ptr, wrtstat::response::del::handler) override {}

  virtual void get( ::wamba::btp::request::get::ptr , ::wamba::btp::response::get::handler ) override {}
  virtual void tree( ::wamba::btp::request::tree::ptr , ::wamba::btp::response::tree::handler ) override {}
  virtual void select( ::wamba::btp::request::select::ptr , ::wamba::btp::response::select::handler ) override {}
  virtual void get_names( ::wamba::btp::request::get_names::ptr , ::wamba::btp::response::get_names::handler ) override {}
  virtual void multi_get( ::wamba::btp::request::multi_get::ptr , ::wamba::btp::response::multi_get::handler ) override {}
};
