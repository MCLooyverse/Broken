#include <string>
#include <iostream>

typedef bool Boolean;
typedef unsigned long long int Natural;
typedef long long int Integer;
typedef double Real;

struct Complex
{
  Real R;
  Real I;

  Complex(const Complex& z) : R(z.R), I(z.I) {}
  Complex(Real a, Real b) : R(a), I(b) {}
  Complex(Real a) : R(a), I(0) {}
  Complex(Integer a) : R(a), I(0) {}
  Complex(Natural a) : R(a), I(0) {}
  Complex(Boolean a) : R(a), I(0) {}
  Complex() : R(0), I(0) {}
  Complex(int a) : R(a), I(0) {}

  Complex& operator=(Boolean x);
  Complex& operator=(Natural x);
  Complex& operator=(Integer x);
  Complex& operator=(Real x);
  Complex& operator=(Complex z);
  Complex& operator=(int x);

  Complex operator*(Boolean x) const;
  Complex operator*(Natural x) const;
  Complex operator*(Integer x) const;
  Complex operator*(Real x) const;
  Complex operator*(Complex z) const;
  friend Complex operator*(Boolean x, Complex z);
  friend Complex operator*(Natural x, Complex z);
  friend Complex operator*(Integer x, Complex z);
  friend Complex operator*(Real x, Complex z);
  Complex operator*(int x);

  std::string str() const;
};

enum MathErr {
  Undefined
};


int main()
{
  std::cout << (Complex(1,1) * Complex(1,1)).str();
  return 0;
}


Boolean floor(Boolean a)
{
  return a;
}
Natural floor(Natural a)
{
  return a;
}
Integer floor(Integer a)
{
  return a;
}
Integer floor(Real a)
{
  if (a < 0)
    return (Integer)(a - 1);
  return (Integer)a;
}
Complex floor(Complex a)
{
  return Complex(floor(a.R), floor(a.I));
}




//===Complex Definitions===
Complex& Complex::operator=(Boolean x)
{
  R = x;
  I = 0;
  return *this;
}
Complex& Complex::operator=(Natural x)
{
  R = x;
  I = 0;
  return *this;
}
Complex& Complex::operator=(Integer x)
{
  R = x;
  I = 0;
  return *this;
}
Complex& Complex::operator=(Real x)
{
  R = x;
  I = 0;
  return *this;
}
Complex& Complex::operator=(Complex z)
{
  R = z.R;
  I = z.I;
  return *this;
}
Complex& Complex::operator=(int x)
{
  R = x;
  I = 0;
  return *this;
}

Complex Complex::operator*(Boolean x) const
{
  if (x)
    return *this;
  return Complex(0);
}
Complex Complex::operator*(Natural x) const
{
  return Complex(R * x, I * x);
}
Complex Complex::operator*(Integer x) const
{
  return Complex(R * x, I * x);
}
Complex Complex::operator*(Real x) const
{
  return Complex(R * x, I * x);
}
Complex Complex::operator*(Complex z) const
{
  return Complex(R * z.R - I * z.I, R * z.I + I * z.R);
}
Complex operator*(Boolean x, Complex z)
{
  if (x)
    return z;
  return 0;
}
Complex operator*(Natural x, Complex z)
{
  return z * x;
}
Complex operator*(Integer x, Complex z)
{
  return z * x;
}
Complex operator*(Real x, Complex z)
{
  return z * x;
}
Complex Complex::operator*(int x)
{
  return Complex(R * x, I * x);
}


std::string Complex::str() const
{
  std::string Output = "";
  Real cR = R, cI = I;
  if (cR < 0)
  {
    Output += "-";
    cR *= -1;
  }

  Real PV = 10;
  while (PV <= cR)
    PV *= 10;

  while (PV > 1)
  {
    PV /= 10;
    Output += '0' + floor(cR / PV);
    cR -= floor(cR / PV) * PV;
  }

  if (cR != 0)
    Output += '.';

  for (Natural i = 0; cR != 0 && i < 6; i++)
  {
    PV /= 10;
    Output += '0' + floor(cR / PV);
    cR -= floor(cR / PV) * PV;
  }



  if (cI < 0)
  {
    Output += " - ";
    cI *= -1;
  }
  else
    Output += " + ";

  PV = 10;
  while (PV <= cI)
    PV *= 10;

  while (PV > 1)
  {
    PV /= 10;
    Output += '0' + floor(cI / PV);
    cI -= floor(cI / PV) * PV;
  }

  if (cI != 0)
    Output += '.';

  for (Natural i = 0; cI != 0 && i < 6; i++)
  {
    PV /= 10;
    Output += '0' + floor(cI / PV);
    cI -= floor(cI / PV) * PV;
  }

  Output += 'i';
  return Output;
}
