#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 10e5 + 5;

int N, P[MAXN], longestInc[MAXN], longestDec[MAXN], ans;

int main()
{
    ifstream in("compin.txt");
    in >> N;
    ans = N - 1;
    for (int i = 1; i <= N; i++)
    {
        in >> P[i];
        longestInc[i] = 1;
        longestDec[i] = 1;
    }
    in.close();

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (P[i] == P[j] + 1)
            {
                longestInc[i] = max(longestInc[i], longestInc[j] + 1);
            }
        }
    }
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = N; j > i; j--)
        {
            if (P[i] == P[j] + 1)
            {
                longestDec[i] = max(longestDec[i], longestDec[j] + 1);
            }
        }
    }

    for (int i = 1; i <= N; i++) printf("%d ", P[i]); puts("");
    for (int i = 1; i <= N; i++) printf("%d ", longestInc[i]); puts("");
    for (int i = 1; i <= N; i++) printf("%d ", longestDec[i]); puts("");

    int maxPyramidLength = 0;
    for (int i = 1; i <= N; i++)
    {
        if (longestInc[i] > 1 && longestDec[i] > 1)
        {
            int num = 2 * min(longestInc[i], longestDec[i]) - 1;
            maxPyramidLength = max(maxPyramidLength, num);
        }
    }
    ans = min(ans, N - maxPyramidLength);

    ofstream out("compout.txt");
    out << ans << endl;
    out.close();
    return 0;
}