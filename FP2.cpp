#include <cstdint>
#include <iostream>
#include "debug.h"      //Manualny debug
#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include "doubler.h"

std::int64_t i{1};

void doPrint()
{
#ifdef ENABLE_DEBUG
   std::cerr<<"doPrint() called\n";
#endif
   PLOGD<<"doPrint() called";
   std::cout<<"Dodawanie\n";
}

void printValue(std::int64_t x)
{
#ifdef ENABLE_DEBUG
   std::cerr<<"printValue(int x) called\n";
#endif
   PLOGD<<"printValue() called";
   std::cout<<"Liczba "<<i<<" = "<<x<<'\n';
   i++;
}

std::int64_t add(std::int64_t x,std::int64_t y)
{
#ifdef ENABLE_DEBUG
   std::cerr<<"add(int x,int y) called\n";
#endif
   PLOGD<<"add(std::int64_t x,std::int64_t y) called";
   return x+y;
}

std::int64_t input1()
{
#ifdef ENABLE_DEBUG
   std::cerr<<"input1() called\n";
#endif
   PLOGD<<"input2() called";
   std::cout<<"Podaj wartosc: ";
   std::int64_t x{};
   std::cin>>x;
   std::cout<<"\n";
   return x;
}

std::int64_t input2()
{
#ifdef ENABLE_DEBUG
   std::cerr<<"input2() called\n";
#endif
   PLOGD<<"input2() called";
   std::cout<<"Podaj wartosc: ";
   std::int64_t y{};
   std::cin>>y;
   std::cout<<"\n";
   return y;
}

int main()
{
#ifdef ENABLE_DEBUG
   std::cerr<<"main() called\n";
#endif
   plog::init(plog::debug,"Logfile.txt"); // Step 2: initialize the logger
   PLOGD<<"main() called"; // Step 3: Output to the log as if you were writing to the console
   doPrint();
   std::int64_t num1{input1()};
   printValue(num1);
   std::int64_t num2{input2()};
   printValue(num2);
   std::cout<<num1<<" + "<<num2<<" = "<<add(num1,num2)<<'\n';
   std::cout<<num1<<" * 2 = "<<doubler(num1)<<" \n";
   std::cout<<num2<<" * 2 = "<<doubler(num2)<<" \n";
#ifdef ENABLE_DEBUG
   std::cerr<<"main() ended\n";
#endif
   return 0;
}

