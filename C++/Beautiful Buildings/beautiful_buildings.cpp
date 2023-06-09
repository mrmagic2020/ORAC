#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/**
 * AIO 2022
 * @link https://orac2.info/problem/aio22buildings/
 * 
 * @mrmagic2020
*/
int main() // PASSED
{
  /**
   * Read the first line of the input file
   * to confirm the number of elements. 
  */
  int n;
  ifstream inputFile("buildin.txt");
  inputFile >> n;

  /**
   * Define variables. 
  */
  int heightList[n], uglinessSum = 0;
  int maxDiff, maxDiffIndex, newHeight;
  for (int i = 0; i < n; i++)
  {
    inputFile >> heightList[i];
    if (i > 0)
    {
      uglinessSum += abs(heightList[i] - heightList[i - 1]);
      if (i == 1)
      {
        maxDiff = abs(heightList[i] - heightList[i - 1]);
        maxDiffIndex = (i - 1);
        newHeight = heightList[i];
      } else {
        int uglinessO = abs(heightList[i - 2] - heightList[i - 1]) + abs(heightList[i] - heightList[i - 1]);
        int heightN = (heightList[i - 2] + heightList[i]) / 2;
        int uglinessN = abs(heightList[i - 2] - heightN) + abs(heightList[i] - heightN);
        int diff = abs(uglinessN - uglinessO);
        if (diff > maxDiff)
        {
          maxDiff = diff;
          maxDiffIndex = (i - 1);
          newHeight = heightN;
        }
      }
      cout << maxDiff << " " << maxDiffIndex << endl;
    }
  }

  inputFile.close();

  int endDiff = abs(heightList[n - 2] - heightList[n - 1]);
  if (abs(endDiff) > abs(maxDiff))
  {
    maxDiff = endDiff;
    maxDiffIndex = (n - 1);
    newHeight = heightList[n - 2];
  }
  cout << maxDiff << " " << maxDiffIndex << endl;

  cout << newHeight << endl;
  if (maxDiffIndex != 0)
  {
    uglinessSum -= abs(heightList[maxDiffIndex] - heightList[maxDiffIndex - 1]);
    uglinessSum += abs(newHeight - heightList[maxDiffIndex - 1]);
  }
  if (maxDiffIndex != (n - 1))
  {
    uglinessSum -= abs(heightList[maxDiffIndex] - heightList[maxDiffIndex + 1]);
    uglinessSum += abs(newHeight - heightList[maxDiffIndex + 1]);
  }
  
  ofstream outputFile("buildout.txt");
  outputFile << uglinessSum;
  outputFile.close();

  return 0;
}