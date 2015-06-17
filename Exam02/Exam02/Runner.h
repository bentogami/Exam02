#include <string>
#include <vector>
#include <fstream>
using namespace std;

#ifndef RUNNER_H
#define RUNNER_H

class Runner {
private:
	string firstName, lastName;
	int pace;

public:
	Runner() {}
	Runner(string f, string l, int p) {
		firstName = f;
		lastName = l;
		pace = p;
	}
	string get_firstname() { return firstName; }
	string get_lastname() { return lastName; }
	int get_pace() { return pace; }

	//For adding a new runner from each line
	//friend istream& operator>>(istream& in, const Runner& r);

	//So I can check those runners or affect them
	friend ostream& operator<<(ostream& out, const Runner& r);

	friend void sortRunners(vector<Runner>& peeps);
};

#endif