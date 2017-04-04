// Devin Patrick
// Y00656800
// Computer Architecture

#include <fstream>
#include <string>


using namespace std;

class SmithCounterClass
{
public:

	SmithCounterClass()
	{
		prediction = 0;
	};

	bool record_Branch(char TakenNotTaken)
	{
		if (TakenNotTaken == 'T')
		{
			record_Branch_Taken();
			return true;
		}

		else if (TakenNotTaken == 'N')
		{
			record_Branch_notTaken();
			return false;
		}

	};
	void record_Branch_Taken()
	{
			prediction++;
			// add if to check boundries
			if (prediction >3)
			{
				prediction = 3;
			}
	};
	void record_Branch_notTaken()
	{
			prediction--;
			// add if to check boundries
			if (prediction < 0)
			{
				prediction = 0;
			}

	};
	bool Get_Prediction()
	{
		return prediction >> 1; // bit shift by one to return last value
	};

private:
	int number_of_bits;
	int prediction;
};
