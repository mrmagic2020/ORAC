#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  int n;
  ifstream inputFile("atlanin.txt");
  inputFile >> n;

  int units[n];
  for (int i = 0; i < n; i++)
    inputFile >> units[i];
  
  int counter = 0;
  int skipToIndex = -1;
  for (int i = 0; i < n; i++)
  {
    cout << skipToIndex << endl;
    if (skipToIndex != -1 && i != skipToIndex)
    {
      continue;
    } else {
      skipToIndex = -1;
    }

    int index = i;
    int unit = units[i];

    cout << i << " " << unit << endl;

      for (int j = i + 1; j < n; j++) // iterate through every unit after
      {
        if (units[j] < unit)
          continue;
        else if (units[j] >= unit)
        {
          if (j == i + 1)
            break;
          else
          {
            counter += (j - i - 1);
            skipToIndex = j;
            break;
          }
        }
      }
  }

  ofstream outputFile("atlanout.txt");
  outputFile << counter;
  return 0;
}