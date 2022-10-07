#include <iostream>
#include "debug.h"      //Manualny debug
#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include "doubler.h"

int i{1};

void doPrint()
{
#ifdef ENABLE_DEBUG
   std::cerr<<"doPrint() called\n";
#endif
   PLOGD<<"doPrint() called";
   std::cout<<"Dodawanie\n";
}

void printValue(int x)
{
#ifdef ENABLE_DEBUG
   std::cerr<<"printValue(int x) called\n";
#endif
   PLOGD<<"printValue() called";
   std::cout<<"Liczba "<<i<<" = "<<x<<'\n';
   i++;
}

int add(int x,int y)
{
#ifdef ENABLE_DEBUG
   std::cerr<<"add(int x,int y) called\n";
#endif
   PLOGD<<"add(int x,int y) called";
   return x+y;
}

int input1()
{
#ifdef ENABLE_DEBUG
   std::cerr<<"input1() called\n";
#endif
   PLOGD<<"input2() called";
   std::cout<<"Podaj wartosc: ";
   int x{};
   std::cin>>x;
   std::cout<<"\n";
   return x;
}

int input2()
{
#ifdef ENABLE_DEBUG
   std::cerr<<"input2() called\n";
#endif
   PLOGD<<"input2() called";
   std::cout<<"Podaj wartosc: ";
   int y{};
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
   int num1{input1()};
   printValue(num1);
   int num2{input2()};
   printValue(num2);
   std::cout<<num1<<" + "<<num2<<" = "<<add(num1,num2)<<'\n';
   std::cout<<num1<<" * 2 = "<<doubler(num1)<<" \n";
   std::cout<<num2<<" * 2 = "<<doubler(num2)<<" \n";
#ifdef ENABLE_DEBUG
   std::cerr<<"main() ended\n";
#endif
   return 0;
}

