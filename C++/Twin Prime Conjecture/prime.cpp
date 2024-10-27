#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 5e5 + 5;

int N;
bool isPrime[MAXN];

void seive(int limit)
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < limit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    ifstream in("primein.txt");
    in >> N;
    in.close();

    seive(N);

    ofstream out("primeout.txt");
    for (int i = 2; i <= N; i++)
    {
        if (isPrime[i])
        {
            out << i << endl;
        }
    }
    out.close();
    return 0;
}