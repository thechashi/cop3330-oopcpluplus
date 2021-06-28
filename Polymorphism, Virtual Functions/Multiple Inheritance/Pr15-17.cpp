// This program demonstrates a class with multiple inheritance.
#include <iostream>
#include "DateTime.h"
using namespace std;

int main()
{
   // Define a DateTime object and use the default
   // constructor to initialize it.
   DateTime emptyDay;

   // Display the object's date and time.
   cout << emptyDay.getDateTime() << endl;

   // Define a DateTime object and initialize it
   // with the date 2/4/60 and the time 5:32:27.
   DateTime pastDay(2, 4, 60, 5, 32, 27);

   // Display the object's date and time.
   cout << pastDay.getDateTime() << endl;
   return 0;
}
