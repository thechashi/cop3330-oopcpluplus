const int MAX = 10;

class DList
{
public:
   DList();			// initialize empty list
   bool Insert(double item);	// inserts item into list (if room)
   double GetElement(unsigned int n) const;	// returns element at index n 
   void Print() const;		// prints the list
   int GetSize() const;		// returns number of elements in list

private:
   double array[MAX];
   int current;		// number of stored items (max is 10)

};
