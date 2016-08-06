#include <string>
#include <iostream>
#include "common/szl.h"

int main()
{
  // using the object logger and two parameters function
  Logger _logger ;
  _logger.log( LogLevel::FATAL, "hi") ;

}
