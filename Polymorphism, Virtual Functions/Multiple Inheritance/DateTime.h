// Specification file for the DateTime class
#ifndef DATETIME_H
#define DATETIME_H
#include "Date.h"
#include "Time.h"

// Constant for string size
const int DT_SIZE = 20;

class DateTime : public Date, public Time
{
protected:
   char dateTimeString[DT_SIZE];
public:
   // Default constructor
   DateTime();
   
   // Constructor
   DateTime(int, int, int, int, int, int);

   // Accessor function
   const char *getDateTime() const
      { return dateTimeString; }
};
#endif
