#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> Graph;

void dfs(Graph& graph, vector<int>& colours, const int colour, const int node,
         int& meet1, int& meet2)
{
    colours[node] = colour;
    if (colour == 0)
        meet1++;
    else
        meet2++;

    for (int v : graph[node])
    {
        if (colours[v] == -1)
        {
            dfs(graph, colours, 1 - colour, v, meet1, meet2);
        }
    }
}

int main()
{
    ifstream in("arthin.txt");
    ofstream out("arthout.txt");

    int N, P;
    in >> N >> P;
    Graph graph(N);
    for (int i = 0, a, b; i < P; i++)
    {
        in >> a >> b;
        graph[a - 1].emplace_back(b - 1);
        graph[b - 1].emplace_back(a - 1);
    }

    int ans = 0;
    vector<int> colours(N, -1);
    for (int i = 0; i < N; i++)
    {
        if (colours[i] == -1)
        {
            int meet1 = 0, meet2 = 0;
            dfs(graph, colours, 0, i, meet1, meet2);
            ans += max(meet1, meet2);
        }
    }
    out << ans << endl;

    in.close();
    out.close();
    return 0;
}