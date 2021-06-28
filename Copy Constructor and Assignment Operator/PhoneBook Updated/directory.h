//----------------- directory.h -----------------

// Declarations for class Directory, where a directory
// is a collection of Entries, declared in "ENTRY.H".

#include "entry.h"

class Directory
{
public:
   Directory();			// Set up empty directory of entries
   ~Directory();		// Deallocate the entry list.

   Directory(const Directory &);		// copy constructor
   Directory& operator= (const Directory &);	// assignment operator

   void Insert();		// Insert an entry into the directory.
   void Lookup();		// Look up a name in the directory.
   void Remove();		// Remove an entry.
   void Update();		// Update an existing entry.
   void DisplayDirectory();	// Display the current directory.

private:
   int	maxSize,		// the maximum allowable number of entries
	currentSize;		// the current number of entries
   Entry* entryList;		// pointer to the list of entries
   void Grow();			// Double the maximum size, when required.
   int FindName(char* aName);	// Return index of an entry, given a name.
};
