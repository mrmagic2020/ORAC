#include <fstream>
#include <iostream>

using namespace std;

int N, A, B, hi, lo;

int main()
{
    ifstream in("archin.txt");
    in >> N >> A >> B;
    in.close();

    if (A > B) swap(A, B);
    hi = max(1, (A - 1) + (B - 1) - (N - 1) + 1);
    lo = min(N, (A - 1) + (B - 1) + 1);

    ofstream out("archout.txt");
    out << hi << " " << lo << endl;
    out.close();
    return 0;
}