#include "print-values.hpp"

void parser::PrintLineData(std::int64_t ln)
{
  std::printf("Line %ld Token: ", ln);
}
void parser::PrintString(std::int64_t ln, scanner::Token & token)
{
  PrintLineData(ln); 
  std::printf(
    "STRINGCONST Value: \"%s\" Len: %lu  Input: %s\n", 
    token.string_value.c_str(), 
    token.string_value.size(), 
    token.token_string.c_str()
  );
}
void parser::PrintNumber(std::int64_t ln, scanner::Token & token)
{
  PrintLineData(ln);
  std::printf(
    "NUMCONST Value: %d  Input: %s\n",
    token.num_value,
    token.token_string.c_str() 
  );
}
void parser::PrintChar(std::int64_t ln, scanner::Token & token)
{
  PrintLineData(ln);
  std::printf(
    "CHARCONST Value: %d  Input: %s\n",
    token.char_value,
    token.token_string.c_str()
  );
}
void parser::PrintBoolean(std::int64_t ln, scanner::Token & token)
{
  PrintLineData(ln);
  std::printf(
    "BOOLCONST Value: %d  Input: %s\n",
    token.num_value,
    token.token_string.c_str()
  );
}
void parser::PrintIdentifer(std::int64_t ln, scanner::Token & token)
{
  PrintLineData(ln);
  std::printf(
    "ID Value: %s\n",
    token.token_string.c_str()
  );
}
void parser::PrintOperator(std::int64_t ln, const char * token)
{
  PrintLineData(ln);
  std::printf(
    "%s\n",
    token
  );
}