#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, K;
int notes[100005];

int p1[100005 / 3];
int p2[100005 / 3];
int p3[100005 / 3];

bool compare(int a, int b)
{
    return a > b;
}

int getMostFrequent(int p[])
{
    int res, maxc = 0, tmp = 0;
    for (int i = 1; i < N / 3; i++)
    {
        if (p[i] == p[i - 1])
        {
            tmp++;
        }
        else
        {
            tmp = 1;
        }
        if (tmp > maxc)
        {
            maxc = tmp;
            res = p[i];
        }
    }
    return res;
}

int ans;
int main()
{
    ifstream fin("melodyin.txt");
    fin >> N >> K;
    if (N != 3)
    {
        for (int i = 0; i < N; i += 3)
        {
            fin >> notes[i] >> notes[i + 1] >> notes[i + 2];
            p1[i / 3] = notes[i];
            p2[i / 3] = notes[i + 1];
            p3[i / 3] = notes[i + 2];
        }

        sort(p1, p1 + N / 3, compare);
        sort(p2, p2 + N / 3, compare);
        sort(p3, p3 + N / 3, compare);
        printf("%d %d, %d %d, %d %d\n", p1[0], p1[1], p2[0], p2[1], p3[0], p3[1]);
        int seq[3] = {getMostFrequent(p1), getMostFrequent(p2), getMostFrequent(p3)};

        printf("%d %d %d\n", seq[0], seq[1], seq[2]);

        for(int i = 0; i < N; i++)
        {
            if (notes[i] != seq[i % 3])
            {
                printf("i=%d, notes[i]=%d, seq=%d\n", i, notes[i], seq[i % 3]);
                ans++;
            }
        }
    }
    fin.close();

    ofstream fout("melodyout.txt");
    fout << ans << endl;
    fout.close();
    return 0;
}