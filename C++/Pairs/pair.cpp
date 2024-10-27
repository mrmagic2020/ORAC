#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 1e5 + 5;

int N, students[2 * MAXN], posOf[MAXN], ans;

int main()
{
    ifstream in("pairin.txt");
    in >> N;
    for (int i = 1; i <= 2 * N; i++)
    {
        in >> students[i];
        if (posOf[students[i]] == 0)  // not yet encountered
        {
            posOf[students[i]] = i;
        }
        else
        {
            int dist = abs(i - posOf[students[i]]);
            ans = max(ans, dist);
        }
    }
    in.close();
    ofstream out("pairout.txt");
    out << ans << endl;
    out.close();
    return 0;
}