#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int Ro, Bo, S, Rp, Bp, ans;

int main()
{
    ifstream in("baublesin.txt");
    in >> Ro >> Bo >> S >> Rp >> Bp;
    in.close();

    if (Rp == 0)
    {
        ans = max(0, Bo + S - Bp + 1);
    }
    else if (Bp == 0)
    {
        ans = max(0, Ro + S - Rp + 1);
    }
    else
    {
        int needed = max(0, Rp - Ro) + max(0, Bp - Bo);
        if (S < needed)
        {
            ans = 0;
        }
        else
        {
            ans += min(S, S - needed + 1);
            if (Ro >= Rp && Bo >= Bp)
            {
                ans += min(Ro - Rp + 1, Bo - Bp + 1);
            }
        }
    }

    ofstream out("baublesout.txt");
    out << ans << endl;
    out.close();
    return 0;
}