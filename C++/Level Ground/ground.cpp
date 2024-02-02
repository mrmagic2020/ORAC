#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int N;

int ans;
int main()
{
    ifstream fin("groundin.txt");
    fin >> N;

    int intensity = 0;
    int altitude;
    fin >> altitude;
    intensity += altitude;
    for (int i = 1; i < N; i++)
    {
        int a;
        fin >> a;
        if (a == altitude)
        {
            intensity += a;
        }
        else
        {
            ans = max(ans, intensity);
            intensity = a;
        }
        altitude = a;
    }
    ans = max(ans, intensity);

    fin.close();

    ofstream fout("groundout.txt");
    fout << ans;
    fout.close();

    return 0;
}