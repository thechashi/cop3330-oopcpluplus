#include <iostream>
#include "date.h"

using namespace std;
int main() {
    Date d;
    d.Show();
    Date d2(4,5,1999);
    d2.SetFormat('T');
    d2.Show();
    return 0;
}
