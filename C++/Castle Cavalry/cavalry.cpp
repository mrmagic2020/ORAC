#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    ifstream in("cavalryin.txt");
    ofstream out("cavalryout.txt");
    int N;
    in >> N;
    set<int> sizes;
    multiset<int> nights;
    for (int i = 0, x; i < N; i++)
    {
        in >> x;
        sizes.insert(x);
        nights.insert(x);
    }

    bool possible = true;
    for (const int& group_size : sizes)
    {
        int nights_cnt = nights.count(group_size);
        if (nights_cnt % group_size != 0)
        {
            possible = false;
            break;
        }
    }

    if (possible)
        out << "YES";
    else
        out << "NO";
    in.close();
    out.close();
    return 0;
}