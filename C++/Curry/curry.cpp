#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int c, r, v, cr, cv, rv;

int main()
{
    ifstream in("curryin.txt");
    ofstream out("curryout.txt");

    in >> c >> r >> v;

    while (max({c, r, v}) != c + r + v)  // more than one dishes left
    {
        // eat the two biggest dishes together
        if (min({c, r, v}) == c)
            r--, v--, rv++;
        else if (min({c, r, v}) == r)
            c--, v--, cv++;
        else
            c--, r--, cr++;
    }

    out << rv << " " << cv << " " << cr << endl;

    in.close();
    out.close();
    return 0;
}