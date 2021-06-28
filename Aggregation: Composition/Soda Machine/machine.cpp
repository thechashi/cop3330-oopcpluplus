//------------------- MACHINE.CPP -------------------

// This file contains definitions of member functions for the classes
// CoinCounter, Dispenser, and SodaMachine

#include <iostream>
#include "machine.h"

using namespace std;

//------------------- CoinCounter Definitions

CoinCounter::CoinCounter(int initial)
// Initialize a counter, setting available change.
{
   amount = 0;
   available = initial;
}

int CoinCounter::CurrentAmount()
// Report amount tendered so far.
{
   return amount;
}

void CoinCounter::AcceptCoin(int amt)
// Handle coin insertion.
{
   amount += amt;
}

void CoinCounter::TakeAll()
// Respond to a sale by taking in all coins so far tendered.
{
   available += amount;
   amount = 0;
}

void CoinCounter::DispenseChange(int amt)
// Return change, if possible.
{
   if (available >= amt)
   {
	cout << "\n*** Change returned: " << amt;
	available -= amt;
   }
   else
	cout << "\n*** EXACT CHANGE ONLY from now on";
}

//------------------- Dispenser Definitions

Dispenser::Dispenser(int num)
// Initialize a dispenser, with num cans.
{
   numCans = num;
}

bool Dispenser::HandleButton()
// Respond to a button push.  
// Return false if no cans left, return true if successful sale.
{
   if (numCans == 0)		// no cans left
	return false;

   // success, make sale and decrement numCans
   numCans--;
   return true;
}

//------------------- SodaMachine Definitions

SodaMachine::SodaMachine()
// Initialize a SodaMachine object, by initializing the coin counter 
// and all can dispensers (implicitly, since they all have default constructors)
// and setting the price of all cans.
{
   price = 75;
}

void SodaMachine::DoCommand(char cmd)
// Get a legal character (Q, D, N, R, C, L, B, O, F) and send
// the appropriate message to either the coin counter or a dispenser.
{
   if ((cmd == 'Q') || (cmd == 'D') || (cmd == 'N') || (cmd == 'R'))
 	DoCoin(cmd);
   else
	DoSelection(cmd);
}

void SodaMachine::DoCoin(char cmd)
// Respond to a coin insertion or a request to return all coins tendered.
{
   int amt;
   switch(cmd)
   {
	case 'R' : amt = counter.CurrentAmount();
				// Return all coins tendered
		   counter.TakeAll();
		   counter.DispenseChange(amt);
		   break;
	case 'Q' : counter.AcceptCoin(25);	break;
	case 'D' : counter.AcceptCoin(10);	break;
	case 'N' : counter.AcceptCoin(5);	break;
   }
}

void SodaMachine::DoSelection(char cmd)
// Respond to a dispenser button push by determining if there's enough
// money inserted to make a sale.  If not, do nothing, else send a 
// request to make a sale.
{
   int tendered = counter.CurrentAmount();	// amount inserted so far
   bool success;				// true for successful sale
						//  false otherwise
	
   if (tendered < price)
	cout << "\n*** Insert more money";
   else
   {
	switch(cmd)		// Send sale message to a dispenser.
	{
	   case 'C' : success = cola.HandleButton(); 	break;
	   case 'L' : success = lite.HandleButton(); 	break;
	   case 'B' : success = root.HandleButton();	break;
	   case 'O' : success = orange.HandleButton();	break;
	   case 'F' : success = free.HandleButton(); 	break;
	}
	
	if (success)		// Dispenser signalled a successful sale
	{
	   cout << "\n*** Sale complete";
	   counter.TakeAll();			// so eat the money
	   if (tendered > price)		// and make change if needed.
		counter.DispenseChange(tendered - price);
	}
	else
	   cout << "\n*** MAKE ANOTHER SELECTION for this from now on";

   }
}

