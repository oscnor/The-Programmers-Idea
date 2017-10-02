#include <algorithm>
#include <iostream>
#include <string>
#include "fraction.hpp"

void print_fraction(Fraction frac);
void menu();

int main()
{
  menu();
  return 0;
}


void print_fraction(Fraction frac)
{
  std::cout << frac.numer << "/" << frac.deno << std::endl;
};

void menu()
{
  std::string fraction1, fraction2, sub1, sub2, oper;
  std::cout << "Enter first fraction: ";
  std::getline(std::cin, fraction1);
  std::cout << std::endl << "Enter second fraction: ";
  std::getline(std::cin, fraction2);
  std::cout << std::endl << "What do you want to do:\n - Addition\n - Subtraction\n - Multiplication\n - Division\n";
  std::cout << std::endl << "Enter operation: ";
  std::getline(std::cin, oper);

  std::transform(oper.begin(),oper.end(),oper.begin(),::tolower);

  int pos;
  pos = fraction1.find("/");
  sub1 = fraction1.substr(0,pos);
  sub2 = fraction1.substr(pos+1);

  
  Fraction frac1(std::stoi(sub1),std::stoi(sub2));

  pos = fraction2.find("/");
  sub1 = fraction2.substr(0,pos);
  sub2 = fraction2.substr(pos+1);
  
  Fraction frac2(std::stoi(sub1),std::stoi(sub2));
  Fraction result();
  
  if(oper == "addition")
    print_fraction(frac1 + frac2);
  else if("subtraction")
    print_fraction(frac1 - frac2);
  else if("multiplication")
    print_fraction(frac1 * frac2);
  else if("division")
    print_fraction(frac1 / frac2);
  else
    std::cout << "Invalid option\n";
};
