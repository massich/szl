#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Sink {
  const std::string file_name ;
  std::ofstream file ;
 public:
  Sink (const std::string _file_name="/tmp/log.txt") : file_name(_file_name) {file.open(file_name);};
  ~Sink() ;
  void log (const std::string message) ;
};

class Logger {
  enum LOGGIG_LEVELS {CRITIC, ERROR, WARNING, INFO, CRAZY} ;
  LOGGIG_LEVELS my_logging_level ;
  Sink s ;
 public:
 Logger( const LOGGIG_LEVELS _level=CRITIC ) : my_logging_level(_level) {} ;
  void log(){std::cout << "hi Logger says " << my_logging_level << std::endl;} ;
} ;
