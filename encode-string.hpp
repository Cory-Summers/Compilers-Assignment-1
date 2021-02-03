#ifndef ENCODE_STRING_HPP
#define ENCODE_STRING_HPP
#include <string>
namespace parser
{
  std::string EncodeString(const char * str);
  std::string EncodeString(const char * str, std::size_t const & length); 
  char EncodeChar(const char * str, std::size_t const & length);
}
#endif