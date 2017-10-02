#include "fraction.hpp"

Fraction::Fraction()
{
  numer = 1;
  deno  = 1;
};

Fraction::Fraction(int _numer)
{
  numer = _numer;
  deno = 1;
};

Fraction::Fraction(int _numer, int _deno)
{
  numer = _numer;
  deno  = _deno;
};


Fraction Fraction::operator+(Fraction param)
{
  int _deno, _numer, numer1, numer2;
  
  numer1 = numer  * param.deno;
  numer2 = deno   * param.numer;
  _deno  = deno   * param.deno;
  _numer = numer1 + numer2;
  
  Fraction result(_numer, _deno);
  result = simplify_fraction(result);
  
  return result;
};

Fraction Fraction::operator-(Fraction param)
{
  int _deno, _numer, numer1, numer2;
  
  numer1 = numer  * param.deno;
  numer2 = deno   * param.numer;
  _deno  = deno   * param.deno;
  _numer = numer1 - numer2;
  
  Fraction result(_numer, _deno);
  result = simplify_fraction(result);
  
  return result;
};

Fraction Fraction::operator*(Fraction param)
{
  int _deno, _numer;

  _numer = numer * param.numer;
  _deno  = deno  * param.deno;
  
  Fraction result(_numer, _deno);
  result = simplify_fraction(result);
  
  return result;
};

Fraction Fraction::operator/(Fraction param)
{
  int _deno, _numer;

  _numer = numer * param.deno;
  _deno  = deno  * param.numer;
  
  Fraction result(_numer, _deno);
  result = simplify_fraction(result);
  
  return result;
};

Fraction Fraction::simplify_fraction(Fraction frac)
{
  int rem, small, large;
  if(frac.numer > frac.deno)
  {
    large = frac.numer;
    small = frac.deno;
  }
  else
  {
    large = frac.deno;
    small = frac.numer;
  }
  rem = large % small;
  while(rem > 0)
  {
    large = small;
    small = rem;
    rem = large % small;
  }
  Fraction result(frac.numer / small, frac.deno / small);
  return result;
};
