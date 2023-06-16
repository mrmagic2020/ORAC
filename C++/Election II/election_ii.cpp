#include <fstream>
#include <iostream>

using namespace std;

class OutPut
{
  public:
  char A;
  char B;
  char C;
  char tie;
  OutPut(char A_c, char B_c, char C_c, char tie_c)
  {
    A = A_c;
    B = B_c;
    C = C_c;
    tie = tie_c;
  }
};

/**
 * AIO 2022
 * @link https://orac2.info/problem/aio22election/
 * 
 * @mrmagic2020
*/
int main() // PASSED
{
  int n;
  ifstream inputFile("elecin.txt");
  ofstream outputFile("elecout.txt");
  inputFile >> n;

  int A = 0, B = 0, C = 0;
  OutPut output('A', 'B', 'C', 'T');
  for (int i = 0; i < n; i++)
  {
    char vote;
    inputFile >> vote;
    if (vote == output.A)
      A++;
    else if (vote == output.B)
      B++;
    else if (vote == output.C)
      C++;
    else
      continue;
  }
  
  char result;
  if (A != B && B != C && C != A)
  {
    int winner; 
    int winner_AB = max(A, B);
    winner = max(winner_AB, C);
    if (winner == A)
      result = output.A;
    else if (winner == B)
      result = output.B;
    else if (winner == C)
      result = output.C;
    else
      result = ' ';
  } else {
    int tied;
    if (A == B)
    {
      tied = A;
      if (C > tied)
        result = output.C;
      else
        result = output.tie;
    }
    else if (B == C)
    {
      tied = B;
      if (A > tied)
        result = output.A;
      else
        result = output.tie;
    }
    else
    {
      tied = C;
      if (B > tied)
        result = output.B;
      else
        result = output.tie;
    }
  }

  outputFile << result;

  inputFile.close();
  outputFile.close();
  return 0;
}