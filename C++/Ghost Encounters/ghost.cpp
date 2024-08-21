#include <fstream>
#include <iostream>
#include <map>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;

int N, K, T[MAXN], X[MAXN], ans;
map<int, int> times;

int main()
{
    ifstream in("ghostin.txt");
    in >> N >> K;
    for (int i = 0; i < N; i++) in >> X[i] >> T[i];
    in.close();

    for (int i = 0; i < N; i++)
    {
        times[T[i] - K * X[i]]++;
    }
    for (auto const& time : times)
    {
        printf("%d %d\n", time.first, time.second);
        ans = max(ans, time.second);
    }

    ofstream out("ghostout.txt");
    out << ans << endl;
    out.close();
    return 0;
}