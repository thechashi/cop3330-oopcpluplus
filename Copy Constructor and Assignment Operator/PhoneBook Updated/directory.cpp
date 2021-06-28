//----------------- directory.cpp -----------------
// Definitions for class Directory

#include <iostream>
#include <cstring>		// for strcmp
#include "fonebook.h"

using namespace std;

Directory::Directory()			
// Set up empty directory of entries.
{ 
   maxSize = 5; 
   currentSize = 0; 
   entryList = new Entry[maxSize];
}

Directory::~Directory()
// This destructor function for class Directory
// deallocates the directory's pointer to its entry list.
{
   delete [] entryList;
}

Directory::Directory(const Directory & D)
// copy constructor.  Initialize object as a copy of D
{
   maxSize = D.maxSize;
   currentSize = D.currentSize;

   // allocate new array of Entry objects
   entryList = new Entry[maxSize];	

   // copy the list over from D
   for (int i = 0; i < currentSize; i++)
	entryList[i] = D.entryList[i];
}

Directory& Directory::operator= (const Directory & D)
// assignment operator (a member function)
// does a similar task to that of the copy constructor
//  but is not a new object, so must delete any existing allocation
//  and must return the assigned value (i.e. this object, *this)
{
   if (this != &D)		// only make the copy if the original is
   {				//  not this same object

      // first, delete the existing array
      delete [] entryList;

      // now do the copy.  Same way we did copy constructor
      maxSize = D.maxSize;
      currentSize = D.currentSize;
      entryList = new Entry[maxSize];
      for (int i = 0; i < currentSize; i++)
	entryList[i] = D.entryList[i];
   }

   return *this;		// return this object
}


void Directory::Insert()
// Insert a new entry into the direrctory.
{
   if (currentSize == maxSize)		// If the directory is full, grow it.
 	Grow();

   cout << "\nType the name, phone number, and address, each followed"
        << "\n by RETURN or ENTER:\n> ";

   cin >> entryList[currentSize++];	// read new entry.
}

void Directory::Lookup()
//  Display the directory entry for a name.
{
   // Prompt the user for a name to be looked up
   char aName[20];
   cout << "\tType the name to be looked up, followed by <Enter>: ";
   cin.getline(aName, 20);
	
   int thisEntry = FindName(aName);	// Locate the name in the directory.
	
   if (thisEntry == -1)
	cout << aName << " not found in current directory\n";
   else
   {
	cout << "\nEntry found: ";
	cout << entryList[thisEntry];	// display entry.
   }
}

void Directory::Remove()
// Remove an entry from the directory.
{
   // Prompt the user for the name to be removed.
   char aName[20];
   cout << "\nType name to be removed, followed by <Enter>: ";
   cin.getline(aName, 20);
	
   int thisEntry = FindName(aName);	// Locate the name in the directory.
	
   if (thisEntry == -1)
	cout << aName << " not found in directory";
   else
   {
	// Shift each succeding element "down" one position in the
	// Entry array, thereby deleting the desired entry.
	for (int j = thisEntry + 1; j < currentSize; j++)
		entryList[j - 1] = entryList[j];
			
	currentSize--;		// Decrement the current number of entries.
	cout << "Entry removed.\n";
   }
}

void Directory::Update()
// Update an existing directory entry by reentering
// each of its values (name, phone, and room number).
{
   cout << "\nPlease enter the name of the entry to be modified: ";
   char aName[20];
   cin.getline(aName, 20);

   int thisEntry = FindName(aName);
	
   if (thisEntry == -1)
	cout << aName << " not found in current directory\n";
   else
   {
	cout << "\nCurrent entry is: \n";
	cout << entryList[thisEntry];		// Display the current entry.
		
	cout << "\nReplace with new entries as follows: \n";
	cin >> entryList[thisEntry];		// Get new values for entry.
   }
}

void Directory::DisplayDirectory()
// Display the current directory entries
// on the standard output (the screen).
{
   if (currentSize == 0)
   {
	cout << "\nCurrent directory is empty.\n";
	return;
   }
	
   // Display a header.
   cout << "\n\t***NAME***\t\t***PHONE***\t\t***ADDRESS***\n\n";
	
   for (int i = 0; i < currentSize; i++)	// For each entry,
	cout << entryList[i];			// send it to output
}

void Directory::Grow()
// Double the size of the directory's entry list
// by creating a new, larger array of entries
// and changing the directory's pointer to refer to
// this new array.
{
   maxSize = currentSize + 5;			// Determine a new size.
   Entry* newList = new Entry[maxSize];		// Allocate a new array.
	
   for (int i = 0; i < currentSize; i++)	// Copy each entry into
	newList[i] = entryList[i];		// the new array.
		
   delete entryList;			// Remove the old array
   entryList = newList;			// Point old name to new array.
}

int Directory::FindName(char* aName)
// Locate a name in the directory.  Returns the
// position of the entry list as an integer if found.
// and returns -1 if the entry is not found in the directory.
{
   for (int i = 0; i < currentSize; i++)	// Look at each entry.
	if (strcmp(entryList[i].GetName(), aName) == 0)
		return i;		// If found, return position and exit.
			
   return -1;				// Return -1 if never found.
}
