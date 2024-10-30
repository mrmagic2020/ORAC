#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

int N, ans;

int main()
{
    ifstream in("artin.txt");
    ofstream out("artout.txt");
    in >> N;
    /**
     * pair<left_pos, height>
     */
    stack<pair<int, int>> blocks;
    for (int i = 0, t, w, h; i < N; i++)
    {
        in >> t >> w >> h;
        while (blocks.size() && blocks.top().first < t) blocks.pop();
        if (blocks.size()) h += blocks.top().second;
        blocks.push({t + w - 1, h});
        ans = max(ans, h);
    }
    out << ans << endl;
    in.close();
    out.close();
    return 0;
}