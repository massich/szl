#include "szl.h"

Sink::~Sink()
{
  file.close() ;
}

void Sink::log (std::string message)
{
  file << message ;
}

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

void Logger::log(const LogLevel l, const std::string message)
{
  std::cout << "[" << l << "]" << message;
}
