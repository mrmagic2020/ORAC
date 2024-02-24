#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

int N;

const int LIMIT = 10004;

int minp[2] = {LIMIT, LIMIT}, maxp[2];

int main()
{
    ifstream fin("artin.txt");
    fin >> N;
    int x, y;
    for (int i = 0; i < N; i++)
    {
        fin >> x >> y;
        minp[0] = min(minp[0], x);
        minp[1] = min(minp[1], y);
        maxp[0] = max(maxp[0], x);
        maxp[1] = max(maxp[1], y);
    }
    fin.close();

    ofstream fout("artout.txt");
    fout << (maxp[0] - minp[0]) * (maxp[1] - minp[1]) << endl;
    fout.close();
    return 0;
}