#include <iostream>
#include <fstream>

using namespace std;

int N;
int a[3], b[3];

int ans;
int main()
{
    ifstream fin("rpsin.txt");
    fin >> N;
    fin >> a[0] >> a[1] >> a[2];
    fin >> b[0] >> b[1] >> b[2];
    fin.close();

    int j[4] = {2, 0, 1, 2};
    for (int i = 0; i < 3; i++)
    {
        if (b[i] > a[j[i]])
        {
            ans += a[j[i]];
            b[i] -= a[j[i]];
            a[j[i]] = 0;
            if (b[i] > a[j[i + 1]])
            {
                b[i] -= a[j[i + 1]];
                a[j[i + 1]] = 0;

                ans -= b[i];
            }
            else
            {
                a[j[i + 1]] -= b[i];
                b[i] = 0;
            }
        }
        else
        {
            ans += b[i];
            a[j[i]] -= b[i];
            b[i] = 0;
        }
    }

    ofstream fout("rpsout.txt");
    fout << ans << endl;
    fout.close();
    return 0;
}