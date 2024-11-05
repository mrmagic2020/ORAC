#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adlist(N + 1);
    for (int i = 0, a, b; i < M; i++)
    {
        cin >> a >> b;
        adlist[a].emplace_back(b);
        adlist[b].emplace_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        cout << adlist[i].size() << " ";
        for (int& v : adlist[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}