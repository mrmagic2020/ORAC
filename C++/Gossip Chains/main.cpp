#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& rel, vector<bool>& visited, int current,
         int target)
{
    if (current == target) return true;
    visited[current] = true;
    for (int& v : rel[current])
    {
        if (!visited[v] && dfs(rel, visited, v, target))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> rel(N);
    int a, b;
    cin >> a >> b;
    while (a != -1)
    {
        rel[a].emplace_back(b);
        rel[b].emplace_back(a);
        cin >> a >> b;
    }
    cin >> a >> b;
    vector<bool> visited(N, false);
    while (a != -1)
    {
        if (dfs(rel, visited, a, b))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        cin >> a >> b;
        visited.assign(N, false);
    }
    return 0;
}