#include <fstream>
#include <iostream>

using namespace std;

int T, ans;
const int notes[] = {100, 20, 5, 1};

int main()
{
    ifstream in("fashin.txt");
    ofstream out("fashout.txt");
    in >> T;

    for (int i = 0; i <= 3; i++)
    {
        if (T < notes[i]) continue;
        if (T % notes[i] == 0)
        {
            ans += T / notes[i];
            break;
        }
        ans += T / notes[i];
        T %= notes[i];
    }

    out << ans << endl;

    in.close();
    out.close();
    return 0;
}