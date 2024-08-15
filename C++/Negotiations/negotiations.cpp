#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

ll N, K, sec[MAXN], sum[MAXN], ans;

bool check(ll score)
{
    // Sliding window to count how many subarrays have greater or equal scores
    ll l = 1, r = 1, cnt = 0;
    while (l <= N)
    {
        while (r <= N && sum[r] - sum[l - 1] < score)
        {
            r++;
        }
        if (sum[r] - sum[l - 1] >= score)
        {
            cnt += N - r + 1; // Every element after r would work as well.
        }
        l++;
    }

    // If the count is greater or equal to K, score will be a potential
    // candidate, thus search for higher scores.
    // printf("score=%lld,cnt=%lld\n", score, cnt);
    if (cnt >= K)
    {
        ans = score;
        return true;
    }
    return false;
}

int main()
{
    cin >> N >> K;
    for (ll i = 1; i <= N; i++)
    {
        cin >> sec[i];
        sum[i] = sum[i - 1] + sec[i];
    }
    // cout << check(19) << endl;

    // Binary search for the suitable score
    ll l = 0, r = sum[N], mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // printf("l=%lld,r=%lld,mid=%lld\n", l, r, mid);
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << ans << endl;
    return 0;
}