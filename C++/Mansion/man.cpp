#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 1e5 + 5;

int N, W, sum[MAXN], ans;

int main()
{
    ifstream in("manin.txt");
    in >> N >> W;
    for (int i = 1; i <= N; i++)
    {
        in >> sum[i];
        sum[i] += sum[i - 1];
    }
    in.close();

    for (int i = W; i <= N; i++)
    {
        ans = max(ans, sum[i] - sum[i - W]);
    }

    ofstream out("manout.txt");
    out << ans << endl;
    out.close();
    return 0;
}