#include <iostream>
#include "dlist.h"

using namespace std;
   
DList::DList()
{
   current = 0;
}

bool DList::Insert(double item)
{
   if (current < MAX)
   {
	array[current] = item;
	current++;
	return true;
   }
   else
	return false;
}

double DList::GetElement(unsigned int n) const
{
   if (n >= current)		// only can get items from used slots
	n = current - 1;
   return array[n];
}

void DList::Print() const
{
   if (current == 0)
   {	cout << "Empty List";
	return;
   }
   int i;
   for (i = 0; i < current-1; i++)
	cout << array[i] << ", ";
   cout << array[i];
}

int DList::GetSize() const
{
   return current;
}
