#include "szl.h"

Sink::~Sink()
{
  file.close() ;
}

void Sink::log (std::string message)
{
  file << message ;
}
