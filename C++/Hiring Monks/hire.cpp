#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 1e5 + 5;

int N, S, M, skills[MAXN], hired[MAXN], sjobs[MAXN], mjobs[MAXN], ans;

int main()
{
    ifstream in("hirein.txt");
    in >> N;
    for (int i = 1; i <= N; i++)
    {
        in >> skills[i];
    }
    in >> S;
    for (int i = 1; i <= S; i++)
    {
        in >> sjobs[i];
    }
    in >> M;
    for (int i = 1; i <= M; i++)
    {
        in >> mjobs[i];
    }
    in.close();

    sort(skills + 1, skills + N + 1);
    sort(sjobs + 1, sjobs + S + 1);
    sort(mjobs + 1, mjobs + M + 1);

    int nextMonkIdx = N;
    for (int i = M; i > 0 && nextMonkIdx <= N; i--)
    {
        while (hired[nextMonkIdx]) nextMonkIdx--;
        if (nextMonkIdx < 1) break;
        if (skills[nextMonkIdx] >= mjobs[i])
        {
            // printf("%d %d\n", skills[nextMonkIdx], mjobs[i]);
            hired[nextMonkIdx] = 1;
            nextMonkIdx--;
            ans++;
        }
    }
    nextMonkIdx = 1;
    for (int i = 1; i <= S && nextMonkIdx <= N; i++)
    {
        while (hired[nextMonkIdx]) nextMonkIdx++;
        if (nextMonkIdx > N) break;
        if (skills[nextMonkIdx] <= sjobs[i])
        {
            // printf("%d %d\n", skills[nextMonkIdx], sjobs[i]);
            hired[nextMonkIdx] = 1;
            nextMonkIdx++;
            ans++;
        }
    }

    ofstream out("hireout.txt");
    out << ans << endl;
    out.close();
    return 0;
}