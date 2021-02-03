#ifndef SCANNER_TOKEN_HPP
#define SCANNER_TOKEN_HPP
#include <fstream>
#include <string>
#include <cstdint>
namespace scanner{
  struct Token{
    std::string token_string;
    char         char_value;
    std::int32_t num_value;
    std::string string_value;
    Token() 
    : token_string()
    , char_value(0)
    , num_value(0)
    , string_value()
    {}
  };
};
#endif //SCANNER_TOKEN_HPP