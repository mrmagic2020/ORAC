#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int ans;
int main()
{
  ifstream fin("atlanin.txt");
  fin >> N;

  vector<int> heights(N);
  for (int i = 0; i < N; ++i)
  {
    fin >> heights[i];
  }

  fin.close();

  // Create two arrays to store the maximum height to the left and right of each position
  vector<int> maxLeft(N), maxRight(N);

  // Calculate maxLeft
  maxLeft[0] = heights[0];
  for (int i = 1; i < N; ++i)
  {
    maxLeft[i] = max(maxLeft[i - 1], heights[i]);
  }

  // Calculate maxRight
  maxRight[N - 1] = heights[N - 1];
  for (int i = N - 2; i >= 0; --i)
  {
    maxRight[i] = max(maxRight[i + 1], heights[i]);
  }

  // Calculate the habitable units
  for (int i = 0; i < N; ++i)
  {
    ans += min(maxLeft[i], maxRight[i]) - heights[i] ? 1 : 0;
  }

  ofstream fout("atlanout.txt");
  fout << ans << endl;
  fout.close();

  return 0;
}
