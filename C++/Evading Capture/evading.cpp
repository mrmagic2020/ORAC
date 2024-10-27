#include <fstream>
#include <iostream>
#include <unordered_set>

using namespace std;
const int MAXN = 1e5 + 5;

int N, E, X, K;
unordered_set<int> ans;

struct Edge
{
    int points_to_node;
    int next_edge_index;
} edges[2 * MAXN];

int edgeid_from_node[MAXN], edge_count;

void add_edge(int from, int to)
{
    edge_count++;
    edges[edge_count].points_to_node = to;
    edges[edge_count].next_edge_index = edgeid_from_node[from];
    edgeid_from_node[from] = edge_count;
}

bool visited[MAXN];
void dfs(int node, int dep)
{
    if (dep > K)
    {
        printf("Did not visit node %d\n", node);
        return;
    };
    // visited[node] = true;
    printf("Visiting node %d, dep=%d\n", node, dep);
    for (int e = edgeid_from_node[node]; e != 0; e = edges[e].next_edge_index)
    {
        int to = edges[e].points_to_node;
        // if (!visited[to])
        // {
        // }
        if (dep == K - 1)
        {
            printf("Next hop from %d to %d is the end!\n", node, to);
            ans.insert(to);
        }
        else
        {
            printf("Hasn't visited node %d, visiting...\n", to);
            dfs(to, dep + 1);
        }
    }
    // visited[node] = false;
}

int main()
{
    ifstream in("evadingin.txt");
    in >> N >> E >> X >> K;
    for (int i = 0, f, t; i < E; i++)
    {
        in >> f >> t;
        add_edge(f, t);
        add_edge(t, f);
    }
    in.close();

    dfs(X, 0);
    for (int node : ans) printf("%d ", node);
    puts("");

    ofstream out("evadingout.txt");
    out << ans.size() << endl;
    out.close();

    return 0;
}