#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// 函数：找到收集签名的最少时间
// 参数：
// 1. positions：储存所有瓢虫位置
// 2. K：需要收集签名的瓢虫数量
// 3. start：开始的掉落点位置
int findMinTimeToCollectSignatures(const vector<int> &positions, int K,
                                   int start)
{
    int N = positions.size();  // 瓢虫的总数量
    int min_time = INT_MAX;    // 初始化最小时间为一个非常大的值

    // 二分查找找到离掉落点最近的瓢虫位置
    int left = 0, right = N - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;  // 取中间索引
        if (positions[mid] < start)
        {
            left = mid + 1;  // 掉落点在中间位置右边
        }
        else
        {
            right = mid;  // 掉落点在中间位置左边或恰好在该位置
        }
    }

    // 使用双指针技术找到最优的K个元素的范围
    int best_left = max(0, left - K);   // 左边界的最小值
    int best_right = min(N - K, left);  // 右边界的最大值

    // 遍历可能的K个瓢虫区间
    for (int i = best_left; i <= best_right; ++i)
    {
        int left_most = positions[i];  // 当前窗口内的最左边瓢虫位置
        int right_most = positions[i + K - 1];  // 当前窗口内的最右边瓢虫位置

        // 计算从起始点到当前窗口收集瓢虫所需的时间
        int time_to_collect_left =
            abs(start - left_most) +
            (right_most - left_most);  // 先去最左边，再去最右边
        int time_to_collect_right =
            abs(start - right_most) +
            (right_most - left_most);  // 先去最右边，再去最左边

        // 取两种可能时间中的最小值
        int min_time_to_collect =
            min(time_to_collect_left, time_to_collect_right);

        // 更新全局最小时间
        min_time = min(min_time, min_time_to_collect);

        // 如果找到完美的最小时间（为0），提前退出循环
        if (min_time == 0) break;
    }

    return min_time;  // 返回最小的收集时间
}

int main()
{
    FILE *input_file = fopen("ladyin.txt", "r");
    FILE *output_file = fopen("ladyout.txt", "w");

    int N, K, Q;
    // 从输入文件中读取N（瓢虫数量）、K（需要收集签名的数量）和Q（掉落点的数量）
    fscanf(input_file, "%d%d%d", &N, &K, &Q);

    // 存储所有瓢虫的位置
    vector<int> positions(N);
    for (int i = 0; i < N; ++i)
    {
        fscanf(input_file, "%d", &positions[i]);
    }

    // 存储所有掉落点的位置
    vector<int> drop_positions(Q);
    for (int i = 0; i < Q; ++i)
    {
        fscanf(input_file, "%d", &drop_positions[i]);
    }

    // 对瓢虫的位置进行排序，以便后续使用二分查找和滑动窗口
    sort(positions.begin(), positions.end());

    // 预分配存储每个掉落点的结果
    vector<int> results(Q);

    // 计算每个掉落点的结果
    for (int i = 0; i < Q; ++i)
    {
        int drop_position = drop_positions[i];  // 当前的掉落点位置
        // 调用函数计算该掉落点收集签名的最小时间
        results[i] =
            findMinTimeToCollectSignatures(positions, K, drop_position);
    }

    for (int i = 0; i < Q; ++i)
    {
        fprintf(output_file, "%d ", results[i]);
    }
    fprintf(output_file, "\n");

    fclose(input_file);
    fclose(output_file);

    return 0;
}
