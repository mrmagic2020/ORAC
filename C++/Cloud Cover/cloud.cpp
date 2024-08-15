#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int N, K, ans = INT_MAX;
vector<int> ppl, sum;

int main()
{
    ifstream in("cloudin.txt");
    in >> N >> K;
    ppl.resize(N + 1);
    sum.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        in >> ppl[i];
        sum[i] = sum[i - 1] + ppl[i];
    }
    in.close();

    int l = 1, r = 1;
    int covered = 0;
    while (l <= N)
    {
        while (r < N && covered < K)
        {
            r++;
            covered++;
        }
        if (covered == K)
        {
            printf("l=%d,r=%d,sum[r - 1]=%d,sum[l-1]=%d\n", l, r, sum[r - 1],
                   sum[l - 1]);
            ans = min(ans, sum[r - 1] - sum[l - 1]);
        }
        l++;
        covered--;
    }

    ofstream out("cloudout.txt");
    out << ans << endl;
    out.close();
    return 0;
}