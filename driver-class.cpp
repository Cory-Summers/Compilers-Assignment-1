#include "driver-class.hpp"
Driver::Driver(int argc, char * argv[])
  : m_input(RetrieveInput(argc, argv))
  {
    std::string name = ((argc < 2) ? "stdin" : argv[1]);
    m_context = parser::Context(name, m_input);
    Initialize();
  }
void Driver::Initialize()
{
  m_scanner = std::make_unique<scanner::TokenLexer>(m_input);
  m_parser  = std::make_unique<parser::TokenParser>(*m_scanner, m_context);
  
}
void Driver::Parse()
{
  if(m_parser->parse() != 0)
  {
    std::cerr << "Parser was unable parse!\n";
  }
}
std::istream * Driver::RetrieveInput(const int argc, char * argv[])
{
  std::istream * stream;
  if(argc < 2)
  {
    m_flags.f_stdin = 0x1;
    return &(std::cin);
  }
  else
  {
    try{
    stream = new std::ifstream();
    dynamic_cast<std::ifstream *>(stream)->open(argv[1]);
    }
    catch(std::ios::failure & e)
    {
      std::cerr << e.what() << '\n';
      delete stream;
    }
    return stream;
  }
}