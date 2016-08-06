#pragma once

#include <iostream>

enum class LogLevel {FATAL, CRITIC, ERROR, WARNING, INFO, TRACE, CRAZY} ;

std::ostream& operator<< (std::ostream& os, LogLevel level)
{
  switch(level)
    {
    case LogLevel::FATAL   : os << "fatal";   break;
    case LogLevel::CRITIC  : os << "critic";  break;
    case LogLevel::ERROR   : os << "error";   break;
    case LogLevel::WARNING : os << "warning"; break;
    case LogLevel::INFO    : os << "info";    break;
    case LogLevel::TRACE   : os << "trace";   break;
    case LogLevel::CRAZY   : os << "crazy";   break;
    default    : os.setstate(std::ios_base::failbit);
    }
  return os;
}

decltype(auto) LOG(LogLevel l=LogLevel::FATAL){
  return std::cout << "[" << l << "]: ";
}
