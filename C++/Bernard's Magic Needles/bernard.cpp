#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 1e5 + 5;

int N, hay[MAXN];

int bsearch(int x)
{
    int l = 0, r = N - 1, mid;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (hay[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (hay[l] == x)
        return l + 1;  // position is 1-indexed
    else
        return -1;
}

int main()
{
    ifstream in("bernardin.txt");
    ofstream out("bernardout.txt");
    in >> N;
    for (int i = 0; i < N; i++)
    {
        in >> hay[i];
    }
    while (true)
    {
        int x;
        in >> x;
        if (x == -1) break;
        int ans = bsearch(x);
        if (ans == -1)
        {
            out << "needle is gone forever" << endl;
        }
        else
        {
            out << ans << endl;
        }
    }
    in.close();
    out.close();
    return 0;
}