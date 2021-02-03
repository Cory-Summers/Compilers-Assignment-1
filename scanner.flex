/* Cory Summers */
%option c++
  // CM == C-
%option yyclass="scanner::TokenLexer"
%option noyywrap
%{
  #include <iostream>
  #include <numeric>
  #include "encode-string.hpp"
  #include "token-lexer-class.hpp"
  #include "context-class.hpp"
  //#include "token_parser.tab.hh"
  using std::cin;
  using std::cout;
  using std::cerr; //I hate using using std::blah;
  //OPERATOR [-][-]|[+][+]|[+\-<>*\/!=][=]|[\[\]()&|=*+\-\/%<>!?:,;]
  #undef  YY_DECL
  #define YY_DECL int scanner::TokenLexer::yylex( \
     parser::TokenParser::semantic_type * const lval, \
     parser::TokenParser::location_type *location, \
     parser::Context & context \
     )

%}

IDENTIFIER  ([A-Za-z][_A-Za-z0-9]*)
STRING   (\"(\\.|[^\"\\])*\")
NUMCONST ([0-9]+)
  //('([^'\\\n]|\\.)')
CHARCONST (\'([\\].|.)\') 
BADCHARCONST (\'([\\].+|.+)\')
WHITESPACE ([ \t]+)
  /*Compound Assignment Operators */

NEWLINE  ([\n]|(\r\n))
%%
%{
  yylval = lval;
%}
{STRING}  { 
  yylval->token.token_string = std::string(yytext);
  yylval->token.string_value = parser::EncodeString(yytext, yyleng);
  return parser::TokenParser::token::T_STRINGCONST;
}
{NUMCONST} {
  
  yylval->token.num_value = std::strtol(yytext, nullptr, 10);
  yylval->token.token_string = std::string(yytext);
  return parser::TokenParser::token::T_NUMCONST;
}
{CHARCONST} {
  yylval->token.token_string = std::string(yytext, yyleng);
  yylval->token.char_value   = parser::EncodeChar(yytext, yyleng);
  return parser::TokenParser::token::T_CHARCONST;
}
{BADCHARCONST} {
  std::cerr << context.file_name << ':' << context.loc.line << ": warning: multi-character wide character constant used\n\t"
  << yytext << '\n';
  yylval->token.token_string = std::string(yytext);
  yylval->token.char_value   = parser::EncodeChar(yytext, yyleng);
  return parser::TokenParser::token::T_CHARCONST;
}
"int"    { return parser::TokenParser::token::TYPE_INT;  }
"char"   { return parser::TokenParser::token::TYPE_CHAR; }
"bool"   { return parser::TokenParser::token::TYPE_BOOL; }
"if"     { return parser::TokenParser::token::T_KEY_IF;   }
"else"   { return parser::TokenParser::token::T_KEY_ELSE; }
"return" { return parser::TokenParser::token::T_KEY_RETURN; }
"for"    { return parser::TokenParser::token::T_KEY_FOR;    }
"while"  { return parser::TokenParser::token::T_KEY_WHILE;  }
"in"     { return parser::TokenParser::token::T_KEY_IN;     }
"by"     { return parser::TokenParser::token::T_KEY_BY;     }
"do"     { return parser::TokenParser::token::T_KEY_DO;     }
"then"   { return parser::TokenParser::token::T_KEY_THEN;   }
"static" { return parser::TokenParser::token::T_KEY_STATIC; }
"break"  { return parser::TokenParser::token::T_KEY_BREAK;  }
"or"     { return parser::TokenParser::token::T_KEY_OR;     }
"and"    { return parser::TokenParser::token::T_KEY_AND;    }
"not"    { return parser::TokenParser::token::T_KEY_NOT;    }
"true"   { yylval->token.num_value = 1; return parser::TokenParser::token::T_BOOLCONST;   }
"false"  { yylval->token.num_value = 0; return parser::TokenParser::token::T_BOOLCONST;   }
{IDENTIFIER} {
  yylval->token.token_string = std::string(yytext);
  return parser::TokenParser::token::T_IDENTIFIER;
}
  /*Non Operator Symbols*/
":"  { return parser::TokenParser::token::T_COLON; }
";"  { return parser::TokenParser::token::T_END_STMT;  }
","  { return parser::TokenParser::token::T_DECL_SEP;  }
"{"  { return parser::TokenParser::token::T_LHS_BRACE; }
"}"  { return parser::TokenParser::token::T_RHS_BRACE; }
"("  { return parser::TokenParser::token::T_LHS_PAREN; }
")"  { return parser::TokenParser::token::T_RHS_PAREN; }
"["  { return parser::TokenParser::token::T_LHS_BRACK; }
"]"  { return parser::TokenParser::token::T_RHS_BRACK; }
  /* Operator Symbols */
  /* Operators will be scoped with parser::TokenParser::token::T_OP_(BLAH) */
"<="  { return parser::TokenParser::token::T_OP_LES_EQ; } //Less then Equals to
"<"   { return parser::TokenParser::token::T_OP_LESS;  }
">"   { return parser::TokenParser::token::T_OP_GREAT; }
">="  { return parser::TokenParser::token::T_OP_GRE_EQ; }
"=="  { return parser::TokenParser::token::T_OP_EQUALIVE; }
"!="  { return parser::TokenParser::token::T_OP_NOT_EQUAL; }
"--"  { return parser::TokenParser::token::T_DECREMENT; }
"++"  { return parser::TokenParser::token::T_INCREMENT; }
":>:" { return parser::TokenParser::token::T_OP_MAX; }
":<:" { return parser::TokenParser::token::T_OP_MIN; }
"+"   { return parser::TokenParser::token::T_OP_PLUS; }
"-"   { return parser::TokenParser::token::T_OP_MINUS; }
"*"   { return parser::TokenParser::token::T_OP_MULTI; }
"\/"  { return parser::TokenParser::token::T_OP_DIVIDE; }
"\%"  { return parser::TokenParser::token::T_OP_MODULO; }
"?"   { return parser::TokenParser::token::T_OP_GENERATOR; }
"+="  { return parser::TokenParser::token::T_OP_ADDASS; }
"-="  { return parser::TokenParser::token::T_OP_MINASS; }
"*="  { return parser::TokenParser::token::T_OP_MULASS; }
"\/=" { return parser::TokenParser::token::T_OP_DIVASS; }
"="   { return parser::TokenParser::token::T_OP_ASSIGN; }
{WHITESPACE} { }
{NEWLINE} { context.loc.lines(1); }
. { std::cerr << "ERROR(" << context.loc.line << "): Invalid or misplaced input character: \'" << yytext << "\'. Character Ignored.\n";}

%%