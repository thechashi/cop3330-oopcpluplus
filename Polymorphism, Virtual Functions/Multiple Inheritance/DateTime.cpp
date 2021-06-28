// Implementation file for the DateTime class
#include <cstring>      // For strcpy and strcat
#include <cstdlib>      // For itoa
#include "DateTime.h"

// Constant for temp array size
const int TEMP_SIZE = 10;

//************************************************
// Default constructor                           *
//************************************************

DateTime::DateTime() : Date(), Time()
{
   strcpy(dateTimeString, "1/1/1900 0:0:0");
}

//************************************************
// Constructor                                   *
//************************************************

DateTime::DateTime(int dy, int mon, int yr, int hr, int mt, int sc) :
    Date(dy, mon, yr), Time(hr, mt, sc)
{
   char temp[TEMP_SIZE]; // Temporary work area for itoa()

   // Store the date in dateTimeString, in the form MM/DD/YY
   strcpy(dateTimeString, itoa(getMonth(), temp, TEMP_SIZE));
   strcat(dateTimeString, "/");
   strcat(dateTimeString, itoa(getDay(), temp, TEMP_SIZE));
   strcat(dateTimeString, "/");
   strcat(dateTimeString, itoa(getYear(), temp, TEMP_SIZE));
   strcat(dateTimeString, " ");

   // Store the time in dateTimeString, in the form HH:MM:SS
   strcat(dateTimeString, itoa(getHour(), temp, TEMP_SIZE));
   strcat(dateTimeString, ":");
   strcat(dateTimeString, itoa(getMin(), temp, TEMP_SIZE));
   strcat(dateTimeString, ":");
   strcat(dateTimeString, itoa(getSec(), temp, TEMP_SIZE));
}

