#include <iostream>
#include "date.h"

using namespace std;

enum Genre {FICTION, MYSTERY, SCIFI, COMPUTER};
int main() {
//    Date d;
//    d.Show();
//    Date d2(4,5,1999);
//    d2.SetFormat('T');
//    d2.Show();
//    return 0;
    char c[3];
    strcpy(c, "");
    cout << c << endl;
    strcpy(c, "DOGGY");
    cout << c << endl;

    Genre g;
    
    cin.getline(c, ' ', 3);

    cout << g << endl;


}
