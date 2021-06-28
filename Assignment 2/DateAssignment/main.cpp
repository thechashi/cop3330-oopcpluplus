#include <iostream>
#include "date.h"

using namespace std;

enum Genre {FICTION, MYSTERY, SCIFI, COMPUTER};
int main() {
    int x = 5;
    int * p = &x;

    cout << p <<endl;

    cout << *p << endl;

    cout << p +1 << endl;

    cout << *(p+1) << endl;


}
