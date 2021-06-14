#include <iostream>
#include "time.h"

using namespace std;

Time::Time()
{
    days = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
}

Time::Time(int sec)
{   if (sec < 0)
    {
        Time();
    }
    else {
        secToFull(sec);
    }
}

Time::Time(int d, int h, int m, int s)
{
    if (d < 0 || h < 0 || m < 0 || s < 0)
    {
        Time();
    }
    else 
    {
        int totalSec = toSec(d, h, m, s);
        secToFull(totalSec);
    }
}

void Time::showTime()
{
    cout << days << '~' << hours << ':' << minutes << ':' << seconds << endl;
}

int Time::toSec(int d, int h, int m, int s)
{
    h = h +  d * 24;
    m = m + h * 60;
    s = s + m * 60;
    return s;
}

void Time::secToFull(int sec)
{
    minutes = sec / 60;
    seconds = sec % 60;
    hours = minutes / 60;
    minutes = minutes % 60;
    days = hours / 24;
    hours = hours % 24;
}

void Time::operator++()
{
    int total_sec = toSec(days, hours, minutes, seconds);
    ++total_sec;
    secToFull(total_sec);
}

void Time::operator++(int)
{
    int total_sec = toSec(days, hours, minutes, seconds);
    total_sec++;
    secToFull(total_sec);
}

void Time::operator--()
{
    int total_sec = toSec(days, hours, minutes, seconds);
    --total_sec;
    secToFull(total_sec);
}

void Time::operator--(int)
{
    int total_sec = toSec(days, hours, minutes, seconds);
    total_sec--;
    secToFull(total_sec);
}

Time operator+(Time& t1, Time& t2)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    int s2 = t2.toSec(t2.days, t2.hours, t2.minutes, t2.seconds);

    int s3 = s1 + s2;

    Time t(s3);
    return t;
}

Time operator+(Time& t1, const int addition)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    s1 += addition;
    Time t(s1);
    return t;
}

Time operator-(Time& t1, Time& t2)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    int s2 = t2.toSec(t2.days, t2.hours, t2.minutes, t2.seconds);

    int s3 = s1 - s2;
    if (s3 > 0)
    {
        Time t(s3);
        return t;
    }
    else 
    {
        Time t(0);
        return t;
    }
}

Time operator-(Time& t1, const int subtraction)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    s1 -= subtraction;
    if (s1 > 0)
    {
        Time t(s1);
        return t;
    }
    else 
    {
        Time t(0);
        return t;
    }
}

Time operator* (Time& t, const int multiplier)
{   int s = t.toSec(t.days, t.hours, t.minutes, t.seconds);
    s = s * 2;
    Time new_t(s);
    return new_t;
}

bool operator< (Time& t1, Time& t2)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    int s2 = t2.toSec(t2.days, t2.hours, t2.minutes, t2.seconds);
    if (s1 < s2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool operator> (Time& t1, Time& t2)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    int s2 = t2.toSec(t2.days, t2.hours, t2.minutes, t2.seconds);
    if (s1 > s2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}


bool operator<= (Time& t1, Time& t2)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    int s2 = t2.toSec(t2.days, t2.hours, t2.minutes, t2.seconds);
    if (s1 <= s2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool operator>= (Time& t1, Time& t2)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    int s2 = t2.toSec(t2.days, t2.hours, t2.minutes, t2.seconds);
    if (s1 >= s2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool operator== (Time& t1, Time& t2)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    int s2 = t2.toSec(t2.days, t2.hours, t2.minutes, t2.seconds);
    if (s1 == s2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool operator != (Time& t1, Time& t2)
{
    int s1 = t1.toSec(t1.days, t1.hours, t1.minutes, t1.seconds);
    int s2 = t2.toSec(t2.days, t2.hours, t2.minutes, t2.seconds);
    if (s1 != s2)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

ostream& operator << (ostream& s, const Time& t)
{
    s << t.days << '~' << t.hours << ':' << t.minutes << ':' << t.seconds << endl;
    return s;
}

istream& operator >> (istream& s, Time& t)
{
    int d, h, m, se;
    char middleChar;

    s >> d >> middleChar >> h >> middleChar >> m >> middleChar >> se;

    if ( d < 0 || h < 0 || m < 0 || se<0)
    {
        Time();
    }
    else 
    {
        int total_sec = t.toSec(d, h, m, se);
        t.secToFull(total_sec);
    }
    return s;
}





