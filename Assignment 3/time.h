#include <iostream>
using namespace std;
class Time
{
    friend Time operator+(Time& t1, Time& t2);
    friend Time operator+(Time& t1, const int addition);
    friend Time operator-(Time& t1, Time& t2);
    friend Time operator-(Time& t1, const int subtraction);
    friend Time operator*(Time& t, const int multiplier);
    friend bool operator<(Time& t1, Time& t2);
    friend bool operator>(Time& t1, Time& t2);
    friend bool operator<=(Time& t1, Time& t2);
    friend bool operator>=(Time& t1, Time& t2);
    friend bool operator==(Time& t1, Time& t2);
    friend bool operator!=(Time& t1, Time& t2);
    friend ostream& operator << (ostream& s, const Time& t);
    friend istream& operator >> (istream& s, Time& t);
public:
        Time();
        Time(int);
        Time(int, int, int, int);
        void showTime();
        int toSec(int, int, int, int);
        void secToFull(int);
        void operator++ ();
        void operator++ (int);
        void operator-- ();
        void operator-- (int);
private:
        int days;
        int hours;
        int minutes;
        int seconds;
};