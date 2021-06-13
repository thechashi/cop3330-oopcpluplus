//--------------- DATE.H ---------------
#include <string>
using namespace std;
class Date
{
public:
    Date();
    Date(int m, int d, int y);

    void Input();
    void Show();
    bool Set(int m, int d, int y);
    int GetMonth();
    int GetDay();
    int GetYear();
    bool SetFormat(char f);
    void Increment(int numDays = 1);
    int Compare(const Date& d);
private:
    int month;
    int day;
    int year;
    char format;
    bool isLeapYear;
    static string monthNames[12];
    static int dayCounts[12];
};