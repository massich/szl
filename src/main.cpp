#include <string>
#include <iostream>
#include "common/szl.h"

int main()
{
	std::cout << "Hello, world!\n" ;
  Sink _sink ;
  Logger _logger ;

  _sink.log("Hello, world\n") ;
  _logger.log() ;
}
