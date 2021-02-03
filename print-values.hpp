#ifndef PRINT_VALUES_HPP
#define PRINT_VALUES_HPP
#include <cstdint>
#include <cstdio>
#include "scanner-token.hpp"
namespace parser
{
  void PrintLineData(std::int64_t ln);
  void PrintString(std::int64_t ln, scanner::Token & token);
  void PrintNumber(std::int64_t ln, scanner::Token & token);
  void PrintChar(std::int64_t ln, scanner::Token & token);
  void PrintBoolean(std::int64_t ln, scanner::Token & token);
  void PrintIdentifer(std::int64_t ln, scanner::Token & token);
  void PrintOperator(std::int64_t ln, const char *);
};
#endif //PRINT_VALUES_HPP