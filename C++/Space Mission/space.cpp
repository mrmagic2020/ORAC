#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, F;
// vector<int> costs;

struct Launch
{
    int day, fuel;
    Launch() : day(0), fuel(0) {}
    Launch(int day, int fuel) : day(day), fuel(fuel) {}
};
vector<Launch> dates;

int ans = -1;

bool sortByFuel(Launch a, Launch b)
{
    return a.fuel < b.fuel;
}

void subtask1()
{
    for (int i = 0; i < N - 1; i++)
    {
        if (dates[i].fuel >= F) continue;
        for (int j = i + 1; j < N; j++)
        {
            if (dates[i].fuel + dates[j].fuel > F) continue;
            ans = max(ans, j - i + 1);
        }
    }
}

void subtask2()
{
    sort(dates.begin(), dates.end(), sortByFuel);
    int p = 0, q = 1;
    while (p < N - 1)
    {
        if (dates[p].fuel >= F) break;

        int maxq = F - dates[p].fuel;
        while (q < N)
        {
            if (dates[q].fuel > maxq) break;
            ans = max(ans, abs(dates[q].day - dates[p].day) + 1);
            q++;
        }

        p++;
        q = p + 1;
    }
}

int main()
{
    ifstream fin("spacein.txt");
    fin >> N >> F;
    dates.resize(N);
    for(int i = 0; i < N; i++)
    {
        dates[i].day = i;
        fin >> dates[i].fuel;
    }
    fin.close();

    if (N <= 1000) subtask1();
    else subtask2();

    ofstream fout("spaceout.txt");
    fout << ans << endl;
    fout.close();

    return 0;
}