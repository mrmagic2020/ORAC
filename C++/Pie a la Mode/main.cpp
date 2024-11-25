#include <iostream>
#include <map>

using namespace std;

int main()
{
    int P;
    cin >> P;
    map<int, int> record;
    for (int i = 0, flavour; i < P; i++)
    {
        cin >> flavour;
        if (record.count(flavour) == 0)
        {
            record[flavour] = 1;
        }
        else
        {
            record[flavour]++;
        }
    }
    pair<int, int> res = {0, 0};
    for (auto& item : record)
    {
        if (item.second > res.second)
        {
            res = item;
        }
    }
    printf("%d %d\n", res.first, res.second);
}