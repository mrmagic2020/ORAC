#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 1e5 + 5;

int N, M, L, shops[MAXN], houses[MAXN], pamphlets[MAXN], R;

bool check(int dist)
{
    vector<bool> used(M, false);
    for (int i = 0; i < M; i++)
    {
        int hpos = houses[i];
        int left_bound = hpos - dist;
        int right_bound = hpos + dist;
        auto lower = lower_bound(shops, shops + N, left_bound);
        auto upper = lower_bound(shops, shops + N, right_bound);
        if (shops[distance(shops, upper)] > right_bound) upper--;
        if (distance(shops, upper) >= N)
        {
            
        }
    }
}

int main()
{
    ifstream in("lscin.txt");
    in >> N >> M >> L;
    for (int i = 0; i < N; i++) in >> shops[i];
    for (int i = 0; i < M; i++) in >> houses[i];
    for (int i = 0; i < M; i++) in >> pamphlets[i];
    in.close();

    int l = 0, r = N - 1, mid;
    // auto bound = lower_bound(shops, shops + N, 10);
    // // if (shops[distance(shops, bound)] >= 8) bound--;
    // cout << *bound << " " << distance(shops, bound) << endl;
    // while (l <= r)
    // {
    //     mid = (l + r) / 2;
    //     if (check(mid))
    //         l = mid + 1;
    //     else
    //         r = mid - 1;
    // }
    return 0;
}