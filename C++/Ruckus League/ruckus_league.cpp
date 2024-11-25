#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    // 打开输入和输出文件
    freopen("ruckusin.txt", "r", stdin);
    freopen("ruckusout.txt", "w", stdout);

    // 读取输入数据
    int N, L, K, M;
    cin >> N >> L >> K >> M;

    // 使用unordered_map存储正向和反向链接
    unordered_map<int, int> links, rlinks;
    for (int i = 0; i < L; ++i)
    {
        int u, v;
        cin >> u >> v;
        links[u] = v;
        rlinks[v] = u;  // 存储反向链接
    }

    // 使用unordered_set跟踪已访问的节点
    unordered_set<int> visited;

    // 存储环、链和单独节点的长度
    vector<int> rings, lines;
    int solos = 0;

    // 遍历所有节点，找出环、链和单独节点
    for (int i = 1; i <= N; ++i)
    {
        if (visited.find(i) == visited.end())
        {
            visited.insert(i);
            int length = 1;
            int currentNode = i;
            bool isRing = false;

            // 遍历正向链接
            int nextNode = links[currentNode];
            while (nextNode != 0 && visited.find(nextNode) == visited.end())
            {
                visited.insert(nextNode);
                length++;
                currentNode = nextNode;
                nextNode = links[currentNode];
                // 检查是否形成环
                if (visited.find(nextNode) != visited.end())
                {
                    isRing = true;
                    break;
                }
            }

            if (isRing)
            {
                rings.push_back(length);
            }
            else
            {
                // 遍历反向链接，查找链
                currentNode = i;
                nextNode = rlinks[currentNode];
                while (nextNode != 0 && visited.find(nextNode) == visited.end())
                {
                    visited.insert(nextNode);
                    length++;
                    currentNode = nextNode;
                    nextNode = rlinks[currentNode];
                }

                // 根据长度分类存储
                if (length == 1)
                {
                    solos++;
                }
                else
                {
                    lines.push_back(length);
                }
            }
        }
    }

    // 统计符合条件的组数
    int groups = 0;
    // 降序排序环的长度
    sort(rings.rbegin(), rings.rend());

    // 统计单独节点（M=1时）
    if (M == 1)
    {
        groups += solos;
    }

    // 统计长度大于等于M的链和环
    for (int len : lines)
    {
        if (len >= M)
        {
            groups++;
        }
    }
    for (int len : rings)
    {
        if (len >= M)
        {
            groups++;
        }
    }

    // 处理链的分组
    for (int &len : lines)
    {
        if (K == 0)
        {
            break;
        }
        while (len / M >= 2 && K > 0)
        {
            groups++;
            len -= M;
            K--;
        }
    }

    // 处理环的分组，注意K的减少逻辑
    for (int &len : rings)
    {
        if (K < 2)
        {
            break;
        }
        int counter = 0;  // 用于记录每处理一个环减少的K的次数
        while (len / M >= 2 && K > 0)
        {
            if (counter == 0)
            {
                K--;  // 首次处理环时额外减少一次K
                counter++;
            }
            K--;
            groups++;
            len -= M;
        }
    }

    // 输出结果
    cout << groups << endl;

    return 0;
}
