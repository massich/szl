#include <string>
#include <iostream>
#include <fstream>
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

  LOG() << "hi" ;

  // go back to old buffer
  std::cout.rdbuf(cout_buff);

  std::cout << "Good: " << local.good() << " Fail: " << local.fail() << " BAD: " << local.bad() << std::endl;

  std::ostringstream local2;
  auto cout_buff2 = std::cout.rdbuf();

  std::cout.rdbuf(local2.rdbuf()); // cout-buffer points to local2

  LOG( static_cast<LogLevel>(-1)) << "hi" ;

  // go back to old buffer
  std::cout.rdbuf(cout_buff2);

  std::cout << "Good: " << local2.good() << " Fail: " << local2.fail() << " BAD: " << local2.bad() << std::endl;

  
}
