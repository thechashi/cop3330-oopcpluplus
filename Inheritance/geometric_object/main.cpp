#include <iostream>
#include "geom.h"

using namespace std;

int main()
{
   cout << "\n** Declaring \"Rectangle r;\"\n";

   Rectangle r;			// invokes default constructors
				// GO(), TDO(), then Rect()


   cout << "\n** Declaring \"Rectangle r1(1, 2, 3, 4, 5, 10, 20);\"\n";

   Rectangle r1(1, 2, 3, 4, 5, 10, 20);

   return 0;
}
