// TLE for subtasks 2, 3 & 5

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C, Q;

struct TileCoord
{
    int x, y, value;
    TileCoord(int x, int y, int value) : x(x), y(y), value(value) {}
    bool operator<(const TileCoord& other) const { return value < other.value; }
};
typedef vector<vector<int>> Tiles;
typedef vector<vector<bool>> TVis;
typedef priority_queue<TileCoord, vector<TileCoord>> TileOrder;

TileOrder getTileOrder(Tiles tiles)
{
    TileOrder pq;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            pq.push({i, j, tiles[i][j]});
        }
    }
    return pq;
}

bool check(TVis visited)
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (!visited[i][j]) return false;
        }
    }
    return true;
}

bool inBounds(int x, int y)
{
    if (x < 1 || x > R || y < 1 || y > C)
    {
        // printf("(%d,%d) out of bounds\n", x, y);
        return false;
    }
    return true;
}

void dfs(Tiles& tiles, TVis& visited, TileCoord root)
{
    int x = root.x, y = root.y, value = root.value;
    if (visited[x][y]) return;
    visited[x][y] = true;
    // printf("x=%d,y=%d,val=%d\n", x, y, value);
    if (inBounds(x - 1, y) && tiles[x - 1][y] < value)
    {
        dfs(tiles, visited, {x - 1, y, tiles[x - 1][y]});
    }
    if (inBounds(x + 1, y) && tiles[x + 1][y] < value)
    {
        dfs(tiles, visited, {x + 1, y, tiles[x + 1][y]});
    }
    if (inBounds(x, y - 1) && tiles[x][y - 1] < value)
    {
        dfs(tiles, visited, {x, y - 1, tiles[x][y - 1]});
    }
    if (inBounds(x, y + 1) && tiles[x][y + 1] < value)
    {
        dfs(tiles, visited, {x, y + 1, tiles[x][y + 1]});
    }
}

int solve(Tiles& tiles)
{
    int ans = 0;
    TileOrder order = getTileOrder(tiles);
    TVis visited(R + 1, vector<bool>(C + 1, false));
    printf("Solving...\n");
    while (!check(visited))
    {
        TileCoord target = order.top();
        order.pop();
        while (visited[target.x][target.y] && !order.empty())
        {
            target = order.top();
            order.pop();
        }
        printf("Pouring from (%d,%d)=%d\n", target.x, target.y, target.value);
        dfs(tiles, visited, target);
        ans++;
    }
    return ans;
}

int main()
{
    ifstream in("janitorin.txt");
    ofstream out("janitorout.txt");
    in >> R >> C >> Q;
    Tiles tiles(R + 1, vector<int>(C + 1));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            in >> tiles[i][j];
        }
    }

    out << solve(tiles) << endl;
    for (int i = 0, x, y, h; i < Q; i++)
    {
        in >> x >> y >> h;
        tiles[x][y] = h;
        out << solve(tiles) << endl;
    }

    in.close();
    out.close();
    return 0;
}