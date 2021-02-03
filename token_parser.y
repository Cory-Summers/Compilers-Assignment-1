%skeleton "lalr1.cc"
%language "C++"
%define api.namespace { parser }
%define parser_class_name { TokenParser }
%locations   // <--
%code requires{
  #include "scanner-token.hpp"
  #include "print-values.hpp"

  namespace parser
  {
    struct Context;
    struct Token //I hate it but it works
    {
      Token() : token() {}
      scanner::Token token;
    };
  }
  namespace scanner
  {
    class TokenLexer;
  };

} //code requiress

%define api.value.type { parser::Token }
%parse-param { scanner::TokenLexer & scanner }
%parse-param { parser::Context & context }
%lex-param   { parser::Context & context}
%code {

  #include "driver-class.hpp"
  #include "context-class.hpp"
  #undef yylex
  #define yylex scanner.yylex
}
%token TYPE_INT TYPE_CHAR TYPE_BOOL
%token T_DECL_SEP  ','
%token T_COLON     ':'
%token T_LHS_BRACK '['
%token T_RHS_BRACK ']'
%token T_END_STMT  ';'
%token T_LHS_PAREN '(' 
%token T_RHS_PAREN ')'
%token T_LHS_BRACE '{'
%token T_RHS_BRACE '}'

%token T_OP_ASSIGN '='
//Keywords
%token T_KEY_IF     "if"
%token T_KEY_THEN   "then"
%token T_KEY_ELSE   "else"
%token T_KEY_WHILE  "while"
%token T_KEY_DO     "do"
%token T_KEY_FOR    "for"
%token T_KEY_BY     "by"
%token T_KEY_RETURN "return"
%token T_KEY_IN     "in"
%token T_KEY_BREAK  "break"
%token T_KEY_OR     "or"
%token T_KEY_AND    "and"
%token T_KEY_STATIC "static"
%token T_KEY_NOT    "not"

%token T_DECREMENT  "--"
%token T_INCREMENT  "++"
%token T_OP_LES_EQ T_OP_LESS T_OP_GREAT T_OP_GRE_EQ T_OP_EQUALIVE T_OP_NOT_EQUAL T_OP_COMP_ASG T_OP_MAX T_OP_MIN
%token T_OP_MINUS T_OP_PLUS T_OP_MULTI T_OP_DIVIDE T_OP_MODULO T_OP_GENERATOR T_OP_ADDASS T_OP_MINASS T_OP_MULASS T_OP_DIVASS
%token <token>T_STRINGCONST 
%token <token>T_NUMCONST
%token <token>T_CHARCONST
%token <token>T_BOOLCONST
%token <token>T_IDENTIFIER 
%%
Start
  : Start Program 
  | Program
  ;
Program
  : Constants
  | Operators 
  | Keywords
  ;
Constants
  : T_STRINGCONST { parser::PrintString(context.loc.line, $1);    }
  | T_NUMCONST    { parser::PrintNumber(context.loc.line, $1);    }
  | T_CHARCONST   { parser::PrintChar(context.loc.line, $1);      }
  | T_BOOLCONST   { parser::PrintBoolean(context.loc.line, $1);   }
  | T_IDENTIFIER  { parser::PrintIdentifer(context.loc.line, $1); }
  ;
Operators
  : T_DECL_SEP  { parser::PrintOperator(context.loc.line, ","); }
  | T_COLON     { parser::PrintOperator(context.loc.line, ":");}
  | T_LHS_BRACK { parser::PrintOperator(context.loc.line, "[");}
  | T_RHS_BRACK { parser::PrintOperator(context.loc.line, "]");}
  | T_END_STMT  { parser::PrintOperator(context.loc.line, ";");}
  | T_LHS_PAREN { parser::PrintOperator(context.loc.line, "(");}
  | T_RHS_PAREN { parser::PrintOperator(context.loc.line, ")");}
  | T_LHS_BRACE { parser::PrintOperator(context.loc.line, "{");}
  | T_RHS_BRACE { parser::PrintOperator(context.loc.line, "}");}
  | T_OP_LES_EQ { parser::PrintOperator(context.loc.line, "LEQ"); }
  | T_OP_LESS   { parser::PrintOperator(context.loc.line, "<"); }
  | T_OP_GREAT { parser::PrintOperator(context.loc.line, ">"); }
  | T_OP_GRE_EQ { parser::PrintOperator(context.loc.line, "GEQ"); }
  | T_OP_EQUALIVE { parser::PrintOperator(context.loc.line, "EQ"); }
  | T_OP_NOT_EQUAL { parser::PrintOperator(context.loc.line, "NEQ"); }
  | T_OP_ADDASS { parser::PrintOperator(context.loc.line, "ADDASS" ); }
  | T_OP_MINASS { parser::PrintOperator(context.loc.line, "MINASS" ); }
  | T_OP_MULASS { parser::PrintOperator(context.loc.line, "MULASS" ); }
  | T_OP_DIVASS { parser::PrintOperator(context.loc.line, "DIVASS" ); }
  | T_OP_MAX { parser::PrintOperator(context.loc.line, "MAX"); }
  | T_OP_MIN { parser::PrintOperator(context.loc.line, "MIN"); }
  | T_OP_MINUS { parser::PrintOperator(context.loc.line, "-"); }
  | T_OP_PLUS { parser::PrintOperator(context.loc.line, "+"); }
  | T_OP_MULTI { parser::PrintOperator(context.loc.line, "*"); }
  | T_OP_DIVIDE { parser::PrintOperator(context.loc.line, "/"); }
  | T_OP_MODULO { parser::PrintOperator(context.loc.line, "%"); }
  | T_OP_GENERATOR { parser::PrintOperator(context.loc.line, "?"); }
  | T_OP_ASSIGN { parser::PrintOperator(context.loc.line, "=");}
  | T_DECREMENT { parser::PrintOperator(context.loc.line, "--");}
  | T_INCREMENT { parser::PrintOperator(context.loc.line, "++");}
  ;
Keywords
  : T_KEY_IF     { parser::PrintOperator(context.loc.line, "IF");}  
  | T_KEY_THEN   { parser::PrintOperator(context.loc.line, "THEN");}  
  | T_KEY_ELSE   { parser::PrintOperator(context.loc.line, "ELSE");}  
  | T_KEY_WHILE  { parser::PrintOperator(context.loc.line, "WHILE");}  
  | T_KEY_DO     { parser::PrintOperator(context.loc.line, "DO");}  
  | T_KEY_FOR    { parser::PrintOperator(context.loc.line, "FOR");}  
  | T_KEY_BY     { parser::PrintOperator(context.loc.line, "BY");}  
  | T_KEY_RETURN { parser::PrintOperator(context.loc.line, "RETURN");}  
  | T_KEY_IN     { parser::PrintOperator(context.loc.line, "IN");}  
  | T_KEY_BREAK  { parser::PrintOperator(context.loc.line, "BREAK");}  
  | T_KEY_OR     { parser::PrintOperator(context.loc.line, "OR");}  
  | T_KEY_AND    { parser::PrintOperator(context.loc.line, "AND");}  
  | T_KEY_STATIC { parser::PrintOperator(context.loc.line, "STATIC");}  
  | T_KEY_NOT    { parser::PrintOperator(context.loc.line, "NOT");}
  | TYPE_INT     { parser::PrintOperator(context.loc.line, "INT");}  
  | TYPE_CHAR    { parser::PrintOperator(context.loc.line, "CHAR");} 
  | TYPE_BOOL    { parser::PrintOperator(context.loc.line, "BOOL");}  
  ; 
%%

void parser::TokenParser::error(const location_type &l, const std::string & error_message)
{
  std::cerr << "Error: " << error_message << " at " << l << "\n";
}