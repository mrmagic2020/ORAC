#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 10e5 + 5;

int N, P[MAXN];
int ls[MAXN];  // 以num结尾的递增序列长度
int rs[MAXN];
int lres[MAXN];  // 以P[i]结尾的递增序列长度
int rres[MAXN];
int ans;

int main()
{
    ifstream in("compin.txt");
    in >> N;
    ans = N - 1;
    for (int i = 1; i <= N; i++)
    {
        in >> P[i];
        ls[P[i]] = ls[P[i] - 1] + 1;
        lres[i] = ls[P[i]];
    }
    in.close();

    for (int i = N; i >= 1; i--)
    {
        rs[P[i]] = rs[P[i] - 1] + 1;
        rres[i] = rs[P[i]];
    }

    for (int i = 1; i <= N; i++) printf("%d ", lres[i]);
    puts("");
    for (int i = 1; i <= N; i++) printf("%d ", rres[i]);
    puts("");

    for (int i = 1; i <= N; i++)
    {
        int sz = min(lres[i], rres[i]) * 2 - 1;
        ans = min(ans, N - sz);
    }

    ofstream out("compout.txt");
    out << ans << endl;
    out.close();
    return 0;
}