#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
const int MAXB = 1e5 + 5;

int B, N, bins[MAXB], ans;
vector<int> sorted_bins;

int main()
{
    ifstream in("tennisin.txt");
    in >> B >> N;
    for (int i = 0; i < B; i++)
    {
        in >> bins[i];
        sorted_bins.emplace_back(bins[i]);
    }
    in.close();

    sort(sorted_bins.begin(), sorted_bins.end());

    int start = 0, remaining = B;
    int sub = sorted_bins[start], tot_sub = 0;
    while (N > sub * remaining)
    {
        N -= sub * remaining;
        tot_sub += sub;
        for (int i = start; i < B; i++)
        {
            sorted_bins[i] -= sub;
            if (sorted_bins[i] == 0)
            {
                start = i;
                remaining--;
            }
        }
        sub = sorted_bins[++start];
    }

    printf("%d %d\n", N, remaining);
    vector<int> r_idx;
    for (int i = 0; i < B; i++)
    {
        if (bins[i] > tot_sub)
        {
            r_idx.emplace_back(i);
        }
    }
    ans = r_idx[(N - 1) % r_idx.size()] + 1;

    ofstream out("tennisout.txt");
    out << ans << endl;
    out.close();
    return 0;
}