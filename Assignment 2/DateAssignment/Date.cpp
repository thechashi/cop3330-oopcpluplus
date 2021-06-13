#include <iostream>
#include "date.h"

using namespace std;

string Date::monthNames[] = {"January", "February", "March", "April",
                             "May", "June", "July", "August",
                             "September", "October", "November", "December"};

int Date::dayCounts[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
{
    month = 1;
    day = 1;
    year = 2020;
    format = 'D';
}


Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
    format = 'D';
}

void Date::Input()
{
    char forwardSlash;
    cout << "Please enter a date:" << endl;
    do
    {
        cin >> month >> forwardSlash >> day >> forwardSlash >> year;
        if (month > 12 || day > 31 || year < 0 || month < 0 || day || 0)
        {
            cout << "Invalid Date. Try again: ";
        } else
        {
            break;
        }
    } while (true);
}
void Date::Show()
{
    if (format == 'T')
    {
        if(month < 10)
        {
            cout << "0";
        }
        cout << month << '/';
        if(day < 10)
        {
            cout << "0";
        }
        cout << day << '/' << year%100 << endl;

    } else if (format == 'L')
    {
        cout << monthNames[month-1] << ' ' << day << ", " << year << endl;
    } else
    {
        cout << month << '/' << day << '/' << year << endl;
    }
}
bool Date::Set(int m, int d, int y)
{   bool report = true;
    if ( m >= 1 and m <= 12)
    {
        // month = m;
    } else report = false;

    if ( d >= 1 and d <= 31)
    {
        // day = d;
    } else report = false;
    if (y>=0)
    {
        // year = y;
    } else report = false;

    if (report == true) {
        month = m;
        day = d;
        year = y;
    }

    return report;
}
int Date::GetMonth()
{
    return month;
}
int Date::GetDay()
{
    return day;
}
int Date::GetYear()
{
    return year;
}
bool Date::SetFormat(char f)
{
    if (f == 'D' || f == 'T' || f == 'L')
    {
        format = f;
        return true;
    } else
        return false;
}
void Date::Increment(int numDays)
{
    if (day + numDays <= dayCounts[month-1])
    {
        day = day + numDays;
    }
}
int Date::Compare(const Date& d)
{
    cout << "COMPARISON" << endl;
    
    return 0;
}