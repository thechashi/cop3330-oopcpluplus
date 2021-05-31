//--------------- FRAC.CPP ---------------
// The class definition for fractions.
//

#include <iostream>
#include "frac.h"

using namespace std;

Fraction::Fraction()
// Default constructor.  Initializes fraction to 0/1
{
   cout << "Howdy";
   numerator = 0;
   denominator = 1;
}

Fraction::Fraction(int n, int d)
// initializes fraction to n/d
// what kind of error checking should be added?
{
   if (SetValue(n,d) == false)
	SetValue(0,1);
}

void Fraction::Input()
// Get a fraction from standard input, in the form "numerator/denominator."
// what kind of error checking should be added?
{
   char divSign;	// used to consume the '/' character during input
   do
   {
      cin >> numerator >> divSign >> denominator;
      if (denominator == 0)
	  cout << "Illegal Fraction.  Try again: ";

   } while (denominator == 0);
}

void Fraction::Show() const
// Display a fraction, in the form "numerator/denominator."
{
   cout << numerator << '/' << denominator;
}

int Fraction::GetNumerator() const
{
   return numerator;
}

int Fraction::GetDenominator() const
{
   return denominator;
}

bool Fraction::SetValue(int n, int d)
// what sort of error checking should be added?
{
   if (d == 0)
      return false;
   else
   {
      numerator = n;
      denominator = d;
      return true;
   }
}


double Fraction::Evaluate() const
// Calculates and returns the decimal value of a fraction
{
   double n = numerator;	// convert numerator to double
   double d = denominator;	// convert denominator to double
   return (n / d);		// compute and return float representation
}
