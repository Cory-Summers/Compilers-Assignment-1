#ifndef TOKEN_LEXER_CLASS_HPP
#define TOKEN_LEXER_CLASS_HPP
#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#include "token_parser.tab.hh"
#include "location.hh"
namespace scanner
{
  class TokenLexer : public yyFlexLexer
  {
    public:
      TokenLexer(std::istream * in) : yyFlexLexer(in) { }
      using yyFlexLexer::yylex;
      virtual
      int yylex(
        parser::TokenParser::semantic_type * const lval, \
        parser::TokenParser::location_type *location, \
        parser::Context & context \
      );
      private:
         parser::TokenParser::semantic_type *yylval = nullptr;
         parser::TokenParser::location_type *loc    = nullptr;
  };
}
#endif //TOKEN_LEXER_CLASS_HPP