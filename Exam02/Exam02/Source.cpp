/*
I, Chase Lake, promise that all the following sloppy and unfinished code was written solely by me
via painfully bashing my head on the keyboard for a large number of hours.
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Runner.h"
using namespace std;


int main() 
{
	vector < Runner > Everyone;
	fstream runners;
	runners.open("Registrants.txt", ios::in);

	if (!runners) {
		cout << "Could not find file \'Registrants\'";
		return 0;
	}
	//This puts that long list of Runners into our vector.
	while (!runners.eof()) {
		//I wanted to create a overloaded operator of istream and Runner to just go runners >> newPerson,
		//but everything I tried made Visual Studio sassy and it would return garbage.
		string fn, ln;
		int p;
		runners >> fn;
		runners >> ln;
		runners >> p;

		Runner newPerson(fn, ln, p);
		Everyone.push_back(newPerson);
	}
	runners.close();

	/*I managed to sort all of the speeds.
	Not the people associated with them.*/
	sortRunners(Everyone);

	cout << Everyone[0] << endl;

	return 0;
}

