#include <iostream>
#include <string>

class Fraction
{
public:
  Fraction();
  Fraction(int _numer);
  Fraction(int _numer, int _deno);

  Fraction operator+(Fraction param);
  Fraction operator-(Fraction param);
  Fraction operator*(Fraction param);
  Fraction operator/(Fraction param);

    
  int numer;
  int deno;
private:

  Fraction simplify_fraction(Fraction frac);
};

