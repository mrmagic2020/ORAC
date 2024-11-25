#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<float> nums(N);
    vector<pair<int, int>> swaps;
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    // Selection sort
    for (int i = 0; i < N - 1; i++)
    {
        int max_idx = i;
        for (int j = max_idx + 1; j < N; j++)
        {
            if (nums[j] > nums[max_idx])
            {
                max_idx = j;
            }
        }
        if (max_idx != i)
        {
            printf("%d %d\n", i + 1, max_idx + 1);
            swap(nums[i], nums[max_idx]);
        }
    }
    printf("all sorted\n");
    // for (const float& num : nums) printf("%f ", num);
}