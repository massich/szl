#include "szl.h"

#include <exception>
#include <mutex>
//#include <typeinfo>

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
    default: throw std::runtime_error("Wrong LogLevel");
    }
  return os;
}

std::mutex log_mutex;
std::ostream& LOG(LogLevel level){
  std::lock_guard<std::mutex> lock(log_mutex);
  auto& logStream = std::cout << "[" << level << "]"<<": ";
  return (logStream);
}
