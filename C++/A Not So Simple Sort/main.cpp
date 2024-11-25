#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(const int& a, const int& b)
{
    if (abs(a) == abs(b))
        return a > b;
    else
        return abs(a) < abs(b);
}

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < N; i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}