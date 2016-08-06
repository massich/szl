#include <string>
#include <iostream>
#include "common/szl.h"

decltype(auto) xx(LogLevel l, std::ostream& os){
  return os << "[" << "xx" << "]: ";
}

decltype(auto) give_me_the_fucking_cout()
{
  return std::cout << "hi";
}

int main()
{
  LOG() << "hello world, the default logging is FATAL\n";
  LOG(LogLevel::INFO) << "this is an INFO message\n";

  xx(LogLevel::INFO, give_me_the_fucking_cout()) << "this is xx function called from main\n";
}
