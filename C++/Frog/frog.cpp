#include <algorithm>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 1e5 + 5;

int N, posts[MAXN], leftl[MAXN], rightl[MAXN], ans;

int main()
{
    ifstream in("frogin.txt");
    in >> N;
    for (int i = 0, lowest = INT_MAX; i < N; i++)
    {
        leftl[i] = lowest;
        in >> posts[i];
        lowest = min(lowest, posts[i]);
    }
    in.close();

    for (int i = N - 1, lowest = INT_MAX; i >= 0; i--)
    {
        rightl[i] = lowest;
        lowest = min(lowest, posts[i]);
    }

    // Iterate through the middle posts
    for (int i = 1; i < N - 1; i++)
    {
        if (leftl[i] >= posts[i] || rightl[i] >= posts[i]) continue;
        ans = max(ans, abs(posts[i] - leftl[i]) + abs(posts[i] - rightl[i]));
    }

    ofstream out("frogout.txt");
    out << ans << endl;
    out.close();
    return 0;
}