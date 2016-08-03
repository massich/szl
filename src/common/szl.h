#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Sink {
 protected:
  const std::string file_name ;
  std::ofstream file ;

 public:
  Sink (const std::string _file_name="/tmp/log.txt") : file_name(_file_name) {file.open(file_name);};
  ~Sink() ;
  void log (const std::string message) ;

};

/* class NullSink : public Sink { */
/*  public: */
/*   void log (const std::string message) {}; */
/* }; */


enum class LogLevel {FATAL, CRITIC, ERROR, WARNING, INFO, TRACE, CRAZY} ;

class Logger {
 private:
  LogLevel my_logging_level ;
  Sink* s ;

 public:
 Logger( const LogLevel _level=LogLevel::CRITIC, Sink* s=nullptr) : my_logging_level(_level) {} ;
  void log(){std::cout << "hi Logger says " << my_logging_level << std::endl;} ;
} ;

