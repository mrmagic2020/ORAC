#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  const int MAX_HUMAN = 100000;
  const int MAX_WIDTH = 1000000;
  int humans[MAX_HUMAN]; // elements array
  int count; // iteration limit
  int width; // addition
  int beam_length;
  ifstream inputFile("alienin.txt");
  inputFile >> count >> width;
  for (int i = 0; i < count; i++)
  {
    inputFile >> humans[i];
  }
  inputFile.close();
  int final_beam = 0; // the maximum number of elements included
  for (int i = 0; i < count; i++) // iterate through every element
  {
    const int limit = humans[i] + width;
    int counter = 1; // the number of elements included in the following range. Initial count is 1 since the range is inclusive.
    for (int j = (i + 1); j < count; j++) // interate through the remaining elements
    {
      if (humans[j] <= limit)
      {
        counter++;
      }
    }
    if (counter > final_beam)
      final_beam = counter;
  }
  ofstream outputFile("alienout.txt");
  outputFile << final_beam;
  outputFile.close();
  return 0;
}