#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 1e6 + 6;

int N, psum[2 * MAXN], heights[2 * MAXN];

int main()
{
    ifstream in("artin.txt");
    in >> N;
    int maxHeight = 0, maxWidth = 0;
    for (int i = 1, t, w, h; i <= N; i++)
    {
        in >> t >> w >> h;
        psum[t] += h;
        psum[t + w + 1] -= h;
        maxWidth = max(maxWidth, t + w + 1);
    }
    in.close();

    for (int i = 1; i <= maxWidth; i++)
    {
        heights[i] = heights[i - 1] + psum[i];
        maxHeight = max(maxHeight, heights[i]);
    }
    ofstream out("artout.txt");
    out << maxHeight << endl;
    out.close();
    return 0;
}