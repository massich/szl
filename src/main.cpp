#include <string>
#include <iostream>
#include "common/szl.h"

int main()
{
	std::cout << "Hello, world!\n" ;
  Sink _sink ;
  Logger _logger ;

  _sink.log("Hello, world\n") ;
  _logger.log( LogLevel::FATAL, "hi") ;
  _sink.describe();

  Sink _sink2 ("/tmp/log2.txt") ;
  Logger _logger2( LogLevel::CRAZY, &_sink2) ;
  _sink2.log("hw 2");
  _sink2.describe();
  _sink.describe();
  _logger2.log( LogLevel::INFO, "hi2") ;
}
