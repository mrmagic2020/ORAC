#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXP = 1e6 + 6;

int N, W, sum[MAXP], ans;

int main()
{
    ifstream in("alienin.txt");
    in >> N >> W;
    int maxp = 0;
    for (int i = 1, p; i <= N; i++)
    {
        in >> p;
        sum[p + 1]++;
        maxp = max(maxp, p);
    }
    in.close();
    for (int i = 1; i <= MAXP - 1; i++)
    {
        sum[i] += sum[i - 1];
    }
    for (int i = W; i <= MAXP - 1; i++)
    {
        ans = max(ans, sum[i] - sum[i - W]);
    }

    ofstream out("alienout.txt");
    out << ans << endl;
    out.close();
    return 0;
}