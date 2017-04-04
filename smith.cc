// Devin Patrick
// Y00656800
// Computer Architecture

#include <fstream>
#include <string>
#include "SmithCounter.cc"
#include "Stats.cc"

using namespace std;

int Bit_Shift(int address)                        // Function to shift bits
{
  return address >>2 & 0X7F;
};

int main()
{
  Stats stats1;

  SmithCounterClass* SMITHARRAY[128];         // Declare Smith array


    ifstream file;
    file.open("branch_trace.dat");                  // Open file to be read

    for (int i=0;i<128;i++)
    {
      SMITHARRAY[i] = new SmithCounterClass();    // loop through array and set all entries to 0
    }

    while (!file.eof())
    {
      int branchAddress;
      char TakenNotTaken;
      bool prediction;

      file >> branchAddress;
      bool predicted = SMITHARRAY[Bit_Shift(branchAddress)]->Get_Prediction();   // read in from file set to Branch Address
      file >> TakenNotTaken;
      bool actual = SMITHARRAY[Bit_Shift(branchAddress)]->record_Branch(TakenNotTaken);
      file >> TakenNotTaken;
      stats1.record_Data(actual, predicted);
    }

    cout << "stats: " <<"\n";
    cout << "Total: " << stats1.get_total() << "\n";
    cout << "Total Taken: "<< stats1.get_total_taken() << "\n";
    cout << "Taken Correct: "<< stats1.get_taken_correct() << "\n";
    cout << "Taken Incorrect "<< stats1.get_taken_incorrect() << "\n";
    cout << "Total Not Taken "<< stats1.get_total_notTaken() << "\n";
    cout << "Not Taken Correct "<< stats1.get_notTaken_correct() << "\n";
    cout << "Not Taken Incorrect "<< stats1.get_notTaken_incorrect() << "\n";
}
