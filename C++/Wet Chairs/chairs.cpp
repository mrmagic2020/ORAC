#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int C, N, K, ans = INT_MAX;
string chairs;

int main()
{
    ifstream in("chairsin.txt");
    in >> C >> N >> K >> chairs;
    in.close();

    int tot = 0, dry = 0;
    int l = 0, r = 0;
    while (l < C)
    {
        while (r < C && (tot < N || dry < N - K))
        {
            if (chairs[r] == 'd') dry++;
            tot++;
            r++;
        }
        printf("l=%d,r=%d,tot=%d,dry=%d\n", l, r, tot, dry);
        if (tot >= N && dry >= (N - K))
        {
            ans = min(ans, tot);
        }
        if (chairs[l] == 'd') dry--;
        tot--;
        l++;
    }

    if (ans == INT_MAX) ans = 0;

    ofstream out("chairsout.txt");
    out << ans << endl;
    out.close();
    return 0;
}