#include <iostream>
#include "Source.h"

int i{1};

void doPrint()
{
   std::cout<<"Dodawanie\n";
}

void printValue(int x)
{
   std::cout<<"Liczba "<<i<<" = "<<x<<'\n';
   i++;
}

int add(int x,int y)
{
   return x+y;
}

int input1()
{
   std::cout<<"Podaj wartosc: ";
   int x{};
   std::cin>>x;
   std::cout<<"\n";
   return x;
}

int input2()
{
   std::cout<<"Podaj wartosc: ";
   int y{};
   std::cin>>y;
   std::cout<<"\n";
   return y;
}

int main()
{
   doPrint();
   int num1{input1()};
   printValue(num1);
   int num2{input2()};
   printValue(num2);
   std::cout<<num1<<" + "<<num2<<" = "<<add(num1,num2)<<'\n';
   std::cout<<num1<<" * 2 = "<<Source(num1)<<" \n";
   std::cout<<num2<<" * 2 = "<<Source(num2)<<" \n";
   return 0;
}

