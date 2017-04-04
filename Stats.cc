//Devin Patrick
// Y00656800
// Computer Architecture

#include <fstream>
#include <string>
#include "Stats.h"

using namespace std;

  Stats::Stats()
  {
    total = 0;
    total_taken = 0;
    total_taken_predicted_correctly = 0;
    total_notTaken = 0;
    total_notTaken_predicted_correctly = 0;
  }

  void Stats::record_Data(bool actual, bool predicted)
  {
    if (actual == true)
    {
      total_taken++;

      if (predicted == true)
      {
        total_taken_predicted_correctly++;
      }
    }

    else if (actual == false)
    {
      total_notTaken++;

      if (predicted == false)
      {
        total_notTaken_predicted_correctly++;
      }
    }
    total = total_taken + total_notTaken;
  }

  int Stats::get_total() const
  {
    return total;
  }

  int Stats::get_total_taken() const
  {
    return total_taken;
  }

  int Stats::get_taken_correct() const
  {
    return total_taken_predicted_correctly;
  }

  int Stats::get_taken_incorrect() const
  {
    return total_taken - total_taken_predicted_correctly;
  }

  int Stats::get_total_notTaken() const
  {
    return total_notTaken;
  }

  int Stats::get_notTaken_correct() const
  {
    return total_notTaken_predicted_correctly;
  }

  int Stats::get_notTaken_incorrect() const
  {
    return total_notTaken - total_notTaken_predicted_correctly;
  }
