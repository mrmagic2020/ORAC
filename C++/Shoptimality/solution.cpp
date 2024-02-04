#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

int N, M;
int H[100010], S[100010], P[100010];

// [Hi-Sj] + Pj => 左边 Hi -Sj+Pj, 右边 -Hi +Sj+Pj
int leftPS[100010], rightPS[100010];
// 靠近i点的左边的最小值和右边的最小值
int lmin[100010], rmin[100010];
// rClosest[i]是最靠近第i个house右边的supermarket (左边即rClosest[i] - 1)
int rClosest[100010];

int ans[100010];
int main()
{
    ifstream fin("shopin.txt");
    fin >> N >> M;
    for (int i = 0; i < N; i++) fin >> H[i];
    for (int i = 0; i < M; i++) fin >> S[i];
    for (int i = 0; i < M; i++) fin >> P[i];
    fin.close();

    /**
     * 预处理
    */

    for (int i = 0; i < M; i++) // 根据题目公式预处理已知数据（排除Hi）
    {
        leftPS[i] = P[i] - S[i];
        rightPS[i] = P[i] + S[i];
    }

    lmin[0] = leftPS[0];
    for (int i = 1; i < M; i++) lmin[i] = min(lmin[i - 1], leftPS[i]); // 方便O(1)获取左边最小值
    rmin[M - 1] = rightPS[M - 1];
    for (int i = M - 2; i >= 0; i--) rmin[i] = min(rmin[i + 1], rightPS[i]); // 方便O(1)获取右边最小值

    /**
     * 找到房子的点在哪里
     * j不归零，时间复杂度O(N+M)
    */
    int j = 0; // j是最靠近house右边的supermarket
    for (int i = 0; i < N; i++)
    {
        while (j < M && S[j] < H[i]) j++; // Sj < Hi, 说明超市在房子左边
        rClosest[i] = j;
    }

    // 遍历house，找到每个house左边最小和右边最小，哪个小哪个就是答案
    for (int i = 0; i < N; i++)
    {
        int left = INT_MAX;
        if (rClosest[i] > 0)
        {
            left = lmin[rClosest[i] - 1] + H[i];
        }
        int right = INT_MAX;
        if (rClosest[i] < M)
        {
            right = rmin[rClosest[i]] - H[i];
        }
        ans[i] = min(left, right);
    }

    ofstream fout("shopout.txt");
    for (int i = 0; i < N; i++) fout << ans[i] << " ";
    fout.close();

    return 0;
}