#include <iostream>
#include <fstream>

using namespace std;

int N;

int main()
{
    ifstream fin("vasesin.txt");
    fin >> N;
    fin.close();

    ofstream fout("vasesout.txt");
    if (N < 6)
    {
        fout << 0 << " " << 0 << " " << 0 << endl;
    }
    else
    {
        fout << 1 << " " << 2 << " " << N - 3 << endl;
    }
    fout.close();
    return 0;
}