//--------------- FRAC.H ---------------

class Fraction
{
public:
   Fraction();			// Set numerator = 0, denominator = 1.
   Fraction(int n, int d=1);	// constructor with parameters

   // standard input/output routines
   void Input();		// input a fraction from keyboard.
   void Show() const;		// Display a fraction on screen

   // accessors
   int GetNumerator() const;
   int GetDenominator() const;

   // mutator
   bool SetValue(int n, int d); // set the fraction's value through parameters

   double Evaluate() const;	// Return the decimal value of a fraction

private:
   int numerator;		// top part (any integer)
   int denominator;		// denom must be non-zero
};



