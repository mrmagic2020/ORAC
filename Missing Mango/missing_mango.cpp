#include <iostream>
#include <fstream>
using namespace std;

int main() // PASSED
{
  int Ix, Cx, Id, Cd, Io[2], Co[2], loc;
  ifstream inputFile("manin.txt");
  inputFile >> Ix >> Cx >> Id >> Cd;
  cout << Ix << " " << Cx << " " << Id << " " << Cd << endl;
  inputFile.close();
  Io[0] = Ix - Id;
  Io[1] = Ix + Id;
  Co[0] = Cx - Cd;
  Co[1] = Cx + Cd;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cout << Io[i] << " " << Co[j] << endl;
      if (Io[i] == Co[j])
        loc = Io[i];
    }
  }
  ofstream outputFile("manout.txt");
  outputFile << loc;
  outputFile.close();
  return 0;
}