#include "Runner.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


void sortRunners(vector<Runner>& peeps)
{
	for (int i = 0; i < peeps.size(); i++)
	{
		int fastestPace = peeps[i].pace;
		int currentFastIndex = i;

		for (int j = i + 1; j < peeps.size(); j++)
		{
			if (fastestPace > peeps[j].pace)
			{
				fastestPace = peeps[j].pace;
				currentFastIndex = j;
			}
		}

		if (currentFastIndex != i)
		{
			peeps[currentFastIndex] = peeps[i];
			peeps[i].pace = fastestPace;
		}
	}
}

ostream& operator<<(ostream& out, const Runner& r)
{
	Runner filled = r;
	out << filled.firstName << " " << filled.lastName << " " << filled.pace << endl;
	return out;
}