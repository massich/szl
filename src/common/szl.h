#pragma once
#include <iostream>

enum class LogLevel {FATAL, CRITIC, ERROR, WARNING, INFO, TRACE, CRAZY} ;


std::ostream& LOG(LogLevel level=LogLevel::FATAL);
