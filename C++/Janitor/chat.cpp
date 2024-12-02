#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int R, C, Q;
vector<vector<int>> heights;
vector<vector<bool>> isLocalMax;
int totalLocalMaxima = 0;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inBounds(int x, int y) { return x >= 1 && x <= R && y >= 1 && y <= C; }

bool computeIsLocalMax(int x, int y)
{
    int h = heights[x][y];
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (inBounds(nx, ny))
        {
            if (h <= heights[nx][ny])
            {
                return false;
            }
        }
    }
    return true;
}

void updateTile(int x, int y)
{
    if (!inBounds(x, y)) return;
    bool oldStatus = isLocalMax[x][y];
    bool newStatus = computeIsLocalMax(x, y);
    if (oldStatus != newStatus)
    {
        isLocalMax[x][y] = newStatus;
        totalLocalMaxima += newStatus ? 1 : -1;
    }
}

int main()
{
    ifstream in("janitorin.txt");
    ofstream out("janitorout.txt");
    in >> R >> C >> Q;

    heights.assign(R + 2,
                   vector<int>(C + 2, -1));  // Padding to avoid bounds checking
    isLocalMax.assign(R + 2, vector<bool>(C + 2, false));

    // Read initial heights
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j) in >> heights[i][j];

    // Initial computation of local maxima
    totalLocalMaxima = 0;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
        {
            isLocalMax[i][j] = computeIsLocalMax(i, j);
            if (isLocalMax[i][j]) ++totalLocalMaxima;
        }

    out << totalLocalMaxima << '\n';

    // Process replacements
    for (int q = 0; q < Q; ++q)
    {
        int x, y, h;
        in >> x >> y >> h;

        // Record old statuses
        vector<pair<int, int>> tilesToUpdate = {{x, y}};
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (inBounds(nx, ny))
            {
                tilesToUpdate.emplace_back(nx, ny);
            }
        }

        // Update height
        heights[x][y] = h;

        // Update local maxima statuses
        for (auto& tile : tilesToUpdate)
        {
            updateTile(tile.first, tile.second);
        }

        out << totalLocalMaxima << '\n';
    }

    in.close();
    out.close();
    return 0;
}