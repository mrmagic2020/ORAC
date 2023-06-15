#include <fstream>
#include <iostream>
using namespace std;

string getOutput(bool isPossible)
{
  if (isPossible) return "YES";
  return "NO";
}

/**
 * AIO 2022
 * @link https://orac2.info/problem/aio22tsp/
 *
 * @mrmagic2020
 */
int main() // PASSED
{
  int n; // the number of days
  ifstream inputFile("tspin.txt");
  ofstream outputFile("tspout.txt");
  inputFile >> n;

  int min[n], max[n]; // minimum and maximum amounts
  for (int i = 0; i < n; i++)
    inputFile >> min[i];
  for (int i = 0; i < n; i++)
    inputFile >> max[i];

  int sold[n]; // store the number of tomatoes sold
  bool isPossible = true;
  sold[0] = min[0]; // the first day should sell the minimum amount
  for (int i = 1; i < n; i++)
  {
    if (min[i] > max[i])
    {
      isPossible = false; // exclude invalid range
      break;
    }

    if (max[i] < sold[i - 1])
    {
      isPossible = false;
      break;
    } else {
      if (sold[i - 1] >= min[i])
        sold[i] = sold[i - 1];
      else
        sold[i] = min[i];
    }
  }

  if (isPossible)
    outputFile << "YES";
  else
    outputFile << "NO";

  inputFile.close();
  outputFile.close();
  return 0;
}
