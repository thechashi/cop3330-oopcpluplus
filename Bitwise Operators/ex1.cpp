#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

int main()
{
  short x = 6891;
  short y = 11318;

  cout << "x = " << x << "\ny = " << y << endl;

  cout << "x & y = " << (x & y) << endl;
  cout << "x | y = " << (x | y) << endl;
  cout << "x ^ y = " << (x ^ y) << endl;
  cout << "x << 2 = " << (x << 2) << endl;
  cout << "y >> 4 = " << (y >> 4) << endl;
  cout << "~x = " << ~x << endl;

}
