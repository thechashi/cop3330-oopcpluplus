//------------------- menu.cpp -------------------

// a driver routine for our soda machine simulation.

#include <iostream>
#include <cctype>		// for toupper
#include "machine.h"

using namespace std;

char GetCommand();
int IsLegal(char cmd);
void ShowMenu();

int main()
{
   SodaMachine	theMachine;	// Initialize the machine.

   ShowMenu();	
   char cmd;
   do
   {
	cmd = GetCommand();		// Get a command from the user,
	if (cmd == 'M')			// if 'M', display the menu
	   ShowMenu();
	else if	(cmd != 'X')		// else if it's not the exit command,
	   theMachine.DoCommand(cmd);	// pass it on to the machine.

   } while (cmd != 'X');		// Quit when the user enters 'X'.
	
}

char GetCommand()
// Get a char from KB and send the char back to main.
{
   char cmd;	  	// the command character entered by the user

   do
   {
  	cout << "\n> ";			// Prompt the user, 
	cin >> cmd;			// get a new command,
	cmd = toupper(cmd);		// and convert it to upper-case

        if (!IsLegal(cmd))		// We got an illegal command
	   cout << "\n*** Unrecognized command.  Type M to see the menu.";

   } while (!IsLegal(cmd));
	
   return cmd;
}

int IsLegal(char cmd)
// Return 1 if cmd is one that we can handle, else return 0.
{
   return  ((cmd == 'Q') || (cmd == 'D') || (cmd == 'N') ||
		 (cmd == 'R') || (cmd == 'C') || (cmd == 'L') ||
		 (cmd == 'B') || (cmd == 'O') || (cmd == 'F') ||
		 (cmd == 'X') || (cmd == 'M'));
}

void ShowMenu()
{
  cout << "Please select one of the following options\n";
  cout << "by pressing the indicated key:\n";
  cout << "\n\tMoney-handling\n";
  cout << "\t\tQ:  Quarter\n";
  cout << "\t\tD:  Dime\n";
  cout << "\t\tN:  Nickel\n";
  cout << "\t\tR:  Return all coins\n";
  cout << "\n\tDrink selection ($0.75 each)\n";
  cout << "\t\tC:  Cola\n";
  cout << "\t\tL:  Lite cola\n";
  cout << "\t\tB:  root Beer\n";
  cout << "\t\tO:  Orange\n";
  cout << "\t\tF:  caffeine-Free, diet, clear, new-age cola\n";
  cout << "\n\tSimulation control\n";
  cout << "\t\tM:  show this Menu\n";
  cout << "\t\tX:  eXit the program\n";
}
