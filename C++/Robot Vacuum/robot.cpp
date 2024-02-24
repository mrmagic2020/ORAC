#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int N;
string s;

int pos[2];

int main()
{
    ifstream fin("robotin.txt");
    fin >> N >> s;
    fin.close();
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'N') pos[1]++;
        else if (s[i] == 'S') pos[1]--;
        else if (s[i] == 'E') pos[0]++;
        else pos[0]--;
    }

    ofstream fout("robotout.txt");
    fout << abs(pos[0]) + abs(pos[1]) << endl;
    fout.close();
    return 0;
}