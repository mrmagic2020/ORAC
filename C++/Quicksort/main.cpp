#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Instruction
{
    int opt, x, y;
};

void dfs(vector<Instruction>& ins, vector<bool>& visited, int& ans, int idx)
{
    if (idx >= ins.size()) return;
    if (visited[idx]) return;
    // printf("visiting line %d...\n", idx + 1);
    ans--;
    visited[idx] = true;
    switch (ins[idx].opt)
    {
        case 1:
            dfs(ins, visited, ans, idx + 1);
            break;
        case 2:
            dfs(ins, visited, ans, ins[idx].x);
            break;
        case 3:
            dfs(ins, visited, ans, ins[idx].x);
            dfs(ins, visited, ans, ins[idx].y);
            break;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<bool> visited(N);
    vector<Instruction> v(N);
    for (int i = 0, opt, x, y; i < N; i++)
    {
        cin >> opt;
        if (opt == 2)
            cin >> x;
        else if (opt == 3)
            cin >> x >> y;
        v[i] = {opt, x - 1, y - 1};
    }
    int ans = v.size();
    dfs(v, visited, ans, 0);
    cout << ans << endl;
    return 0;
}