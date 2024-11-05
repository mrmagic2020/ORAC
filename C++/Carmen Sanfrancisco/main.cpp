#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Edge
{
    int city, transport;
    Edge() : city(0), transport(0) {}
    Edge(int c, int t) : city(c), transport(t) {}
};

int main()
{
    ifstream in("wherein.txt");
    ofstream out("whereout.txt");

    int N, M;
    in >> N >> M;

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0, a, b, c; i < M; i++)
    {
        in >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int K;
    in >> K;
    vector<int> moves(K);
    for (int i = 0; i < K; i++)
    {
        in >> moves[i];
    }

    unordered_set<int> possibleCities;
    for (int i = 1; i <= N; i++) possibleCities.insert(i);

    for (int& move : moves)
    {
        unordered_set<int> newPossibleCities;
        for (int city : possibleCities)
        {
            for (Edge& e : graph[city])
            {
                if (e.transport == move)
                {
                    newPossibleCities.insert(e.city);
                }
            }
        }
        possibleCities = newPossibleCities;
        // printf("Move=%d, possible cities=", move);
        // for (int city : newPossibleCities)
        // {
        //     printf("%d,", city);
        // }
        // printf("\n");
    }

    if (possibleCities.empty())
        out << "Impossible" << endl;
    else
    {
        for (int city : possibleCities)
        {
            out << city << endl;
        }
    }

    return 0;
}