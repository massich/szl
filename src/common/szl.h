#pragma once
#include <iostream>
#include <exception>
#include <typeinfo>

enum class LogLevel {FATAL, CRITIC, ERROR, WARNING, INFO, TRACE, CRAZY} ;


std::ostream& operator<< (std::ostream& os, LogLevel level);
std::ostream& LOG(LogLevel level=LogLevel::FATAL);
