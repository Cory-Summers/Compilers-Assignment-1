#ifndef CONTEXT_CLASS_HPP
#define CONTEXT_CLASS_HPP
#include <iostream>
#include <string>
#include "position.hh"
namespace parser
{
  struct Context
  {
    using loc_type = position;
    Context() {};
    Context(std::string, std::istream *);
    std::string file_name;
    std::istream * file;
    loc_type loc;
  };
  inline parser::Context::Context(std::string name, std::istream * ptr)
  : file_name(name)
  , file(ptr)
  , loc(&name, 1, 1)
  {}
}
#endif //CONTEXT_CLASS_HPP