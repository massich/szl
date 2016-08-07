#include <string>
#include <iostream>
#include <sstream>
#include "common/szl.h"

decltype(auto) xx(LogLevel l, std::ostream& os){
  return os << "[" << "xx" << "]: ";
}

decltype(auto) give_me_the_fucking_cout()
{
  return (std::cout) ;
}

int main()
{
  std::ostringstream local;
  auto cout_buff = std::cout.rdbuf();

  std::cout.rdbuf(local.rdbuf()); // cout-buffer points to local

  LOG() << "hello world, the default logging is FATAL\n";

  // go back to old buffer
  std::cout.rdbuf(cout_buff);

  std::cout << "local content: -------\n" << local.str() << "-------\n";
}
