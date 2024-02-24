#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> p;

int ans;
int main()
{
    ifstream fin("distin.txt");
    fin >> N >> K;
    p.resize(N);
    for (int i = 0; i < N; i++)
    {
        fin >> p[i];
    }
    fin.close();

    sort(p.begin(), p.end());

    int lastChosen = -1;
    for (int &pos : p)
    {
        if (lastChosen == -1 || pos - lastChosen >= K)
        {
            lastChosen = pos;
            ans++;
        }
    }

    ofstream fout("distout.txt");
    fout << ans << endl;
    fout.close();
    
    return 0;
}