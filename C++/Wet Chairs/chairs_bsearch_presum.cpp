#include <fstream>
#include <iostream>
#include <string>

using namespace std;
const int MAXN = 1e5 + 5;

int C, N, K, dsum[MAXN], wsum[MAXN];
char chairs[MAXN];

bool check(int width)
{
    for (int i = width; i <= C; i++)
    {
        int wet = wsum[i] - wsum[i - width];
        int dry = dsum[i] - dsum[i - width];
        printf("width=%d: %d wet, %d dry\n", width, wet, dry);
        if (dry + wet >= N && dry >= (N - K)) return true;
    }
    return false;
}

int main()
{
    ifstream in("chairsin.txt");
    in >> C >> N >> K >> (chairs + 1);
    in.close();

    for (int i = 1; i <= C; i++)
    {
        dsum[i] = dsum[i - 1];
        wsum[i] = wsum[i - 1];
        if (chairs[i] == 'd')
            dsum[i]++;
        else
            wsum[i]++;
    }

    int l = 1, r = C, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        printf("l=%d,r=%d,mid=%d\n", l, r, mid);
        if (!check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }

    ofstream out("chairsout.txt");
    out << l << endl;
    out.close();
    return 0;
}