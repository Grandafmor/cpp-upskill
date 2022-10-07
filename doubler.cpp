#include <iostream>
#include "doubler.h"
#include "debug.h"
int doubler(int x)
{
#ifdef ENABLE_DEBUG
   std::cerr<<"doubler(int x) called\n";
#endif
   return x*2;
}