#include <string>
#include <iostream>

class Sink {
  std::string file_name = "/tmp/log.txt" ;
public:
  void log(){std::cout << "hi Sink" << std::endl;} ;
};

class Logger {
  enum LOGGIG_LEVELS {CRITIC, ERROR, WARNING, INFO, CRAZY} ;
  LOGGIG_LEVELS my_logging_level ;
public:
  Logger( const LOGGIG_LEVELS _level=CRITIC ) : my_logging_level(_level) {} ;
  void log(){std::cout << "hi Logger says " << my_logging_level << std::endl;} ;
} ;

int main()
{
	std::cout << "Hello, world!\n" ;
  Sink _sink ;
  Logger _logger ;

  _sink.log() ;
  _logger.log() ;
}
