#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <climits>

using namespace std;

int N, M;
vector<int> h;
vector<pair<int, int>> sp;

ofstream fout("shopout.txt");

void subtask1()
{
    for (int hpos : h)
    {
        int minBad = INT_MAX;
        for (pair<int, int> super : sp)
        {
            minBad = min(minBad, super.second + abs(hpos - super.first));
        }
        fout << minBad << " ";
    }
}

void subtask2()
{
    unordered_map<int, int> supermap(sp.begin(), sp.end());
    for (int hpos : h)
    {
        int ptr = hpos;
        int tmpAns;
        while (ptr++)
        {
            auto super = supermap.find(ptr);
            if (super != supermap.end())
            {
                tmpAns = 0 + abs(hpos - super->first);
                break;
            }
        }
        ptr = hpos;
        while (ptr--)
        {
            auto super = supermap.find(ptr);
            if (super != supermap.end())
            {
                tmpAns = min(tmpAns, 0 + abs(hpos - super->first));
                break;
            }
        }
        fout << tmpAns << "";
    }
}

int main()
{
    ifstream fin("shopin.txt");
    fin >> N >> M;
    h.resize(N);
    sp.resize(M);
    
    int maxPrice = 0;
    for (int i = 0; i < N; i++)
    {
        fin >> h[i];
    }
    for (int i = 0; i < M; i++)
    {
        fin >> sp[i].first;
    }
    for (int i = 0; i < M; i++)
    {
        fin >> sp[i].second;
    }

    if (N <= 1000 && M <= 1000) // subtask 1
    {
        subtask1();
    }
    else if (maxPrice == 0)
    {
        subtask2();
    }

    fin.close();
    fout.close();

    return 0;
}