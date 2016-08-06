#include <string>
#include <iostream>
#include "common/szl.h"

int main()
{
  LOG() << "hello world, the default logging is FATAL\n";
  LOG(LogLevel::INFO) << "this is an INFO message\n";
}
