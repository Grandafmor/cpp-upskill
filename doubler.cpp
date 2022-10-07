#include <iostream>
#include "doubler.h"
#include "debug.h"
#include <plog/Log.h>
std::int64_t doubler(std::int64_t x)
{
#ifdef ENABLE_DEBUG
   std::cerr<<"doubler(int x) called\n";
#endif
   PLOGD<<"doubler() called";
   return x*2;
}