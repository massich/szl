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
  void describe() {std::cout << "Sink::\"" << file_name <<"\"" << std::endl;};
};

class NullSink : public Sink {
 public:
  void log (const std::string message) {};
};


enum class LogLevel {FATAL, CRITIC, ERROR, WARNING, INFO, TRACE, CRAZY} ;

template <typename Enumeration>
auto as_integer(Enumeration const value)
-> typename std::underlying_type<Enumeration>::type
{
  return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

class Logger {
 private:
  LogLevel my_logging_level ;
  Sink* s ;

 public:
  Logger( const LogLevel _level=LogLevel::CRITIC, Sink* s=nullptr) : my_logging_level(_level) {} ;
  void log(const LogLevel l, const std::string message);
} ;

