#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "SmithCounter.h"
#include "Stats.h"
using namespace std;

int main()
{
    SmithCounter  c;
    Stats    stats;
    bool startPrediction;

    for (int i=0; i < 45; i++)
	{
	cout << setw(5) << i << "  Initally: " << c.get_State() << " predicing: " 
			<< c.get_Prediction() << " then after ";
	if (rand() & 1)
	    {
	    c.record_Branch_Taken();
	    stats.record_Data(true, c.get_Prediction());
	    cout << setw(10) << "TAKEN";
	    }
	 else
	    {
	    c.record_Branch_Not_Taken();
	    stats.record_Data(false, c.get_Prediction());
	    cout << setw(10) << "NOT TAKEN";
	    }

	cout << " State is: " << c.get_State() << endl;
	}
 
    cout << "\n\nStats:\n" << stats << endl;

    return 0;
}
