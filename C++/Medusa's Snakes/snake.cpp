#include <iostream>
#include <fstream>

using namespace std;
const int MAXN = 1e5 + 5;

int N;
char s[MAXN];

bool hasSnake(int len)
{
    char letters[] = {'S', 'N', 'A', 'K', 'E'};
    int currentLetter = 0, currCnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == letters[currentLetter])
        {
            currCnt++;
        }
        if (currCnt >= len)
        {
            if (currentLetter == 4)
            {
                return true;
            }
            currentLetter++;
            currCnt = 0;
        }
    }
    return false;
}

int main()
{
    ifstream in("snakein.txt");
    in >> N >> s;
    in.close();

    int l = 0, r = N, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (hasSnake(mid)) l = mid + 1;
        else r = mid - 1;
    }

    ofstream out("snakeout.txt");
    out << l - 1 << endl;
    out.close();
    return 0;
}