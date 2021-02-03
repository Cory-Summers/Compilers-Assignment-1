#ifndef DRIVER_CLASS_HPP
#define DRIVER_CLASS_HPP
#include "token_parser.tab.hh"
#include "token-lexer-class.hpp"
#include "context-class.hpp"
#include <memory>
class Driver
{
  public:
  Driver(int argc, char * argv[]);
  void Parse();
  void Initialize();
  private:
    std::istream * RetrieveInput(const int, char * argv[]);
    struct Flags
    {
      int f_stdin = 0;
    } m_flags;
    std::istream * m_input;
    std::unique_ptr<scanner::TokenLexer> m_scanner;
    std::unique_ptr<parser::TokenParser> m_parser;
    parser::Context m_context;
};
#endif //DRIVER_CLASS_HPP