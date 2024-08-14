#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, ans;
string A, B, P;

int main()
{
    ifstream in("chimin.txt");
    ofstream out("chimout.txt");

    in >> N >> A >> B >> P;

    bool fail = false;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        if (A[i] == B[i] && A[i] == P[i]) v[i] = (i == 0) ? 2 : v[i - 1];
        else if (A[i] == P[i]) v[i] = 0;
        else if (B[i] == P[i]) v[i] = 1;
        else
        {
            fail = true;
            break;
        }
    }
    if (fail)
    {
        out << "PLAN FOILED" << endl;
        in.close();
        out.close();
        return 0;
    }
    for (int i = 1; i < N; i++)
    {
        printf("%d ", v[i]);
        if (v[i] != v[i - 1] && v[i - 1] != 2) ans++;
    }
    puts("");

    out << "SUCCESS" << endl << ans << endl;

    in.close();
    out.close();
    return 0;
}