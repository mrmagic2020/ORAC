#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("snapin.txt");
    ofstream out("snapout.txt");
    int N;
    in >> N;
    vector<int> cards(2 * N + 1, 0);
    for (int i = 1; i <= 2 * N; i++)
    {
        in >> cards[i];
    }

    int ans = 0;
    if (cards[1] == cards[2]) ans++;
    for (int i = 2; i <= 2 * N; i++)
    {
        if (cards[i] == cards[i - 1] || cards[i] == cards[i - 2])
        {
            ans++;
        }
    }
    out << ans << endl;

    in.close();
    out.close();
    return 0;
}