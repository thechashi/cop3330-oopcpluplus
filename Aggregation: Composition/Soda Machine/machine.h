//------------------- MACHINE.H -------------------

// This file contains the declarations of the classes having to do
// with the soda machine.  A SodaMachine object is a manager that
// contains (and handles communications among) a ChangeCounter,
// five Dispenser objects, and has the member data price (of a can).

class CoinCounter
{
public:
   CoinCounter(int initial = 100);// Initialize a counter, setting available change.
	
   int CurrentAmount();			// Report amount tendered so far.
   void AcceptCoin(int amt);		// Handle coin insertion.
   void TakeAll();			// Accept all coins in response to a sale.
   void DispenseChange(int amt);	// Return change, if possible.

private:
   int amount;			// the amount tendered so far
   int available;		// the amount available for making change
};

class Dispenser
{
public:
   Dispenser(int num = 24);	// Initialize with default number of cans.
   bool HandleButton();		// Try to make a sale

private:
   int numCans;			// the number of cans available
};

class SodaMachine
{
public:
   SodaMachine();		// Initialize a machine.
   void DoCommand(char cmd);	// process a command from the user
	
private:
   CoinCounter counter;		// A soda machine contains a coin dispenser,
   Dispenser	cola,		// five can dispensers,
		lite,
		root,
		orange,
		free;
   int price;			// and the price of a can of soda.
	
   void DoCoin(char cmd);	// Handle a coin event.
   void DoSelection(char cmd);	// Handle a drink button press.
};
