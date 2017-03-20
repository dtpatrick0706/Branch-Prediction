// SmithCounter.cpp
// Devin Patrick
// Computer Architecture

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SmithCounter
{
private:
	int SmithArray[150] = {}; // initialize array to 0 for not taken

public:
	int Taken;
	int Not_Taken;

	SmithCounter()
	{
		for (int i = 0; i < 150; i++)
		{
			SmithArray[i] = 0; //loop through array and set all entires to 0
		}
	}
	bool PredictBranch(int address) // will return a bool value
	{
		Index = ((address >> 2) & 0x7F);  // bit shift 2 places 
		return SmithArray[Index] >> 1;  // return last bit value 
	}
	void SmithEntry(int address, char taken)
	{
		Index = ((address >> 2) & 0X7F);
		if (taken == 'T')
		{
			SmithArray[Index]++; // Increment Index if taken
			Taken++;
		}
		else if (taken == 'N')
		{
			SmithArray[Index]--; // Decrement Index if not taken
			Not_Taken++;
		}

		// SmithArray[Index] = SmithArray[Index] & 3;

		if (SmithArray[Index] < 0)			// Defensive Programming
		{
			SmithArray[Index] = 0;			// If value at Index in the array is less then 0 set it to 0
		}
		if (SmithArray[Index] > 3)
		{
			SmithArray[Index] = 3; 			// If value at Index in the array is greater than 3 set it to 3
		} 

	}

};
