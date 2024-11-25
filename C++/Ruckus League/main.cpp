#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Child
{
    Child* left = nullptr;
    Child* right = nullptr;
    int group_id = -1;
};

void dfs(Child* child, const int& group_id, int& num_in_group, bool& cycle)
{
    if (child->group_id != -1)
    {
        if (child->group_id == group_id)  // Cycle
        {
            cycle = true;
        }
        return;
    }
    child->group_id = group_id;
    num_in_group++;
    if (child->left != nullptr) dfs(child->left, group_id, num_in_group, cycle);
    if (child->right != nullptr)
        dfs(child->right, group_id, num_in_group, cycle);
}

int main()
{
    ifstream in("ruckusin.txt");
    ofstream out("ruckusout.txt");
    int N, L, K, M;
    in >> N >> L >> K >> M;
    vector<Child> children(N + 1);
    vector<int> num_in_group(N + 1, 0);
    vector<bool> isCycle(N + 1, false);
    for (int i = 0, l, r; i < L; i++)
    {
        in >> l >> r;
        children[l].left = &children[r];
        children[r].right = &children[l];
    }

    int tot_groups = 0;
    for (int i = 1; i <= N; i++)
    {
        if (children[i].group_id == -1)
        {
            int num = 0;
            bool cycle = false;
            dfs(&children[i], ++tot_groups, num, cycle);
            num_in_group[tot_groups] = num;
            isCycle[tot_groups] = cycle;
        }
    }

    int ans = 0;
    bool count_only = false;
    vector<int> cycle_groups;
    for (int i = 1; i <= tot_groups; i++)
    {
        printf("group=%d, num=%d, cycle=%d\n", i, num_in_group[i],
               static_cast<int>(isCycle[i]));
        if (K == 0) count_only = true;
        if (num_in_group[i] < M) continue;
        if (num_in_group[i] < 2 * M)
            ans++;
        else
        {
            if (isCycle[i])
            {
                cycle_groups.emplace_back(i);
                continue;
            }
            if (count_only)
            {
                ans++;
                continue;
            }
            else
            {
                int most_usable_lol =
                    num_in_group[i] / M - 1;  // n groups needs (n - 1) cuts
                int actual_used_lol = min(most_usable_lol, K);
                ans += actual_used_lol + 1;
                K -= actual_used_lol;
            }
        }
    }
    for (int i = 0; i < (int)cycle_groups.size(); i++)
    {
        int group_id = cycle_groups[i];
        printf("group=%d, num=%d, cycle=%d\n", group_id, num_in_group[group_id],
               static_cast<int>(isCycle[group_id]));

        if (K <= 1) count_only = true;  // One lollipop is useless in cycles
        if (num_in_group[group_id] < M) continue;
        if (num_in_group[group_id] < 2 * M)
            ans++;
        else
        {
            if (count_only)
            {
                ans++;
                continue;
            }
            int most_usable_lol = num_in_group[group_id] / M;
            int actual_used_lol = min(most_usable_lol, K);
            ans += actual_used_lol;
            if (actual_used_lol != 1)  // No point breaking a cycle
            {
                K -= actual_used_lol;
            }
        }
    }

    out << ans << endl;

    in.close();
    out.close();
    return 0;
}