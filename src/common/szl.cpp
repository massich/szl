#include "szl.h"

class wrong_LogLevel_exeption: public std::bad_cast
 {
   virtual const char* what() const throw()
   {
     return "Wrong LogLevel";
   }
} wrong_LogLevel;

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
    default: throw wrong_LogLevel;
    }
  return os;
}

std::ostream& LOG(LogLevel level){
  auto& logStream = std::cout << "[" << level << "]: ";
  return (logStream);
}
