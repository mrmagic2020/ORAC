#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream in("laserin.txt");
    ofstream out("laserout.txt");
    int N, ans = 0;
    string A, B;
    in >> N >> A >> B;
    for (int i = 0, tmp = 0; i < 2 * N; i++)
    {
        if (A[i] == 'D' && B[i] == 'R') tmp++;
        if (A[i] == 'R' && B[i] == 'D') tmp--;
        ans = max(ans, tmp);
    }
    out << ans << endl;

    in.close();
    out.close();
    return 0;
}