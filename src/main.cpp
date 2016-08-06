#include <string>
#include <iostream>
#include "common/szl.h"

int main()
{
  Logger _logger ;

  _logger.log( LogLevel::FATAL, "hi") ;
}
