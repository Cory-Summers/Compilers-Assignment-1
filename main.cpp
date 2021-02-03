#include <iostream>
#include "parser.hpp"
int main(int argc, char * argv[])
{
  Driver driver(argc, argv); //
  driver.Parse();
  return 0;
}

/*
int main(int argc, char * argv[])
{
  int type_flag = 0;
  std::istream * input_stream = parser::RetrieveInput(argc, argv, type_flag);
  std::string file_name = ((argc < 2) ? "stdin" : argv[1]);
  parser::Context context(file_name, input_stream);
  parser::TokenParser parser;
  parser.
  if(type_flag == 1)
    delete input_stream;
  return 0;

}
*/