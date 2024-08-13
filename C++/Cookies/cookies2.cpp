#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int D, C, p1, c1, p2, c2;

int main()
{
    ifstream fin("cookiesin.txt");
    fin >> D >> C >> p1 >> c1 >> p2 >> c2;
    fin.close();
    
    int ans0 = D * C;
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 1, rate1 = C, rate2 = C, b1 = 0, b2 = 0; i <= D; i++)
    {
        ans1 += rate1;
        if (!b1 && ans1 >= p1)
        {
            ans1 -= p1;
            rate1 += c1;
            b1 = 1;
        }

        ans2 += rate2;
        if (!b2 && ans2 >= p2)
        {
            ans2 -= p2;
            rate2 += c2;
            b2 = 1;
        }
    }
    int ans12 = 0;
    for (int i = 1, rate = C, b1 = 0, b2 = 0; i <= D; i++)
    {
        ans12 += rate;
        if (!b1 && ans12 >= p1)
        {
            ans12 -= p1;
            rate += c1;
            b1 = 1;
        }
        if (!b2 && ans12 >= p2)
        {
            ans12 -= p2;
            rate += c2;
            b2 = 1;
        }
    }
    int ans21 = 0;
    for (int i = 1, rate = C, b1 = 0, b2 = 0; i <= D; i++)
    {
        ans21 += rate;
        if (!b2 && ans21 >= p2)
        {
            ans21 -= p2;
            rate += c2;
            b2 = 1;
        }
        if (!b1 && ans21 >= p1)
        {
            ans21 -= p1;
            rate += c1;
            b1 = 1;
        }
    }

    printf("%d %d %d %d %d\n", ans0, ans1, ans2, ans12, ans21);
    ofstream fout("cookiesout.txt");
    fout << max(max(ans0, max(ans1, ans2)), max(ans12, ans21)) << endl;
    fout.close();
    return 0;
}