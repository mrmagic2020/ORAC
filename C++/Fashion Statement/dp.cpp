#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int T;
const vector<int> notes = {100, 20, 5, 1};
vector<int> dp;  // dp[i] stores the minimum number of notes needed to create i

int main()
{
    ifstream in("fashin.txt");
    ofstream out("fashout.txt");
    in >> T;

    dp.resize(T + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= T; i++)
    {
        for (const int &note : notes)
        {
            if (i - note >= 0 && dp[i - note] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - note] + 1);
            }
        }
    }

    out << dp[T] << endl;

    in.close();
    out.close();
    return 0;
}