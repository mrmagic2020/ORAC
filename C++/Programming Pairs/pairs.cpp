#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 1e5 + 5;

int N, A, B, s[MAXN], ans = 0;

int main()
{
    ifstream in("pairsin.txt");
    in >> N >> A >> B;
    for (int i = 0; i < N; i++)
    {
        in >> s[i];
    }
    in.close();

    sort(s, s + N);

    int l = N - 1, r = N - 1;
    for (int i = 0; i < N; i++)
    {
        l = max(l, i);  // if (l < i) l = i;
        r = max(r, i);  // if (r < i) r = i;
        while (l > i && s[i] + s[l] >= A)
            l--;  // Make s[l] the smallest (inclusive) value that can fulfill
                  // the minimum A for any higher value
        while (r > i && s[i] + s[r] > B)
            r--;  // Make s[r] the biggest (inclusive) value that can fulfill
                  // the maximum B for any lower value down to s[i]
        // s[l] can pair up with any s[X] where X => [l + 1, r], therefore
        // add (l - r) to the answer
        ans += (r - l);
    }

    ofstream out("pairsout.txt");
    out << ans << endl;
    out.close();

    return 0;
}