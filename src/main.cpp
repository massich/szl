#include <string>
#include <iostream>

#include <boost/log/trivial.hpp>

#include "common/szl.h"

int main()
{
  // BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
  // BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
  // BOOST_LOG_TRIVIAL(info) << "An informational severity message";
  // BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
  // BOOST_LOG_TRIVIAL(error) << "An error severity message";
  // BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

	std::cout << "Hello, world!\n" ;
  Sink _sink ;
  Logger _logger ;

  _sink.log("Hello, world\n") ;
  _logger.setSink(&_sink);
  _logger.log( LogLevel::FATAL, "hi") ;
  _sink.describe();
  std::cout << "getSinkptr (" << _logger.getSinkPtr() << ")\n";
  _logger.getSinkPtr()->describe();

  Sink _sink2 ("/tmp/log2.txt") ;
  Logger _logger2( LogLevel::CRAZY) ;
  _logger2.setSink(&_sink2);
  _logger.log( LogLevel::FATAL, "hi") ;
  _sink2.log("hw 2");
  _sink2.describe();
  _sink.describe();
  _logger2.log( LogLevel::INFO, "hi2") ;
  std::cout << "getSinkptr (" << _logger2.getSinkPtr() << ")\n";
  _logger2.getSinkPtr()->describe();

  return 0;
}

