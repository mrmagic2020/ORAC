#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int groupSize = 0, isCycle = 0;
vector<int> adj[100005];
bool visited[100005];

void dfs(int node)
{
    if (visited[node]) return;
    visited[node] = true;
    ++groupSize;
    for (int neighbor : adj[node])
    {
        if (adj[node].size() == 1) isCycle = 1;
        dfs(neighbor);
    }
}

int main()
{
    freopen("ruckusin.txt", "r", stdin);
    freopen("ruckusout.txt", "w", stdout);
    int n, l, k, m;
    cin >> n >> l >> k >> m;

    for (int i = 0, a, b; i < l; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));

    vector<int> cycleGroups, lineGroups;
    int validGroups = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            groupSize = 0, isCycle = 0;
            dfs(i);
            if (isCycle)
                cycleGroups.push_back(groupSize);
            else
                lineGroups.push_back(groupSize);
            if (groupSize >= m) ++validGroups;
        }
    }

    sort(cycleGroups.rbegin(), cycleGroups.rend());
    sort(lineGroups.rbegin(), lineGroups.rend());

    // cycle groups
    for (int i = 0; i < (int)cycleGroups.size() && k; ++i)
    {
        while (cycleGroups[i] >= 2 * m && k)
        {
            ++validGroups;
            --k;
            cycleGroups[i] -= m;
        }
    }

    // line groups
    for (int i = 0; i < (int)lineGroups.size() && k > 1; ++i)
    {
        if (lineGroups[i] >= 2 * m)
        {
            ++validGroups;
            k -= 2;
            lineGroups[i] -= m;

            while (lineGroups[i] >= 2 * m && k)
            {
                ++validGroups;
                --k;
                lineGroups[i] -= m;
            }
        }
    }

    cout << validGroups;
    return 0;
}
