#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>

using namespace std;
const int MAXN = 1e5 + 5;

int N, K, Q, P[MAXN], maxp;

int findLeft(int pos, int val)
{
    int l = 1, r = N, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (P[mid] < val)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (l > N || P[l] > pos) return -1;
    return l;
}

int findRight(int pos, int val)
{
    int l = 1, r = N, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (P[mid] <= val)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (r < 1 || P[r] < pos) return -1;
    return r;
}

bool check(int pos, int width, int &ans)
{
    int leftmost = max(0, pos - width);
    int left_bug_idx = findLeft(pos, leftmost);
    int rightmost = min(maxp, pos + width);
    int right_bug_idx = findRight(pos, rightmost);

    printf("pos=%d,width=%d,%d %d %d %d\n", pos, width, leftmost, left_bug_idx, rightmost, right_bug_idx);

    int cnt = 0;
    if (left_bug_idx == -1 && right_bug_idx == -1)
    {
        cnt = 0;
    }
    else if (left_bug_idx == right_bug_idx)
    {
        cnt = 1;
    }
    else if (left_bug_idx == -1)
    {
        int right_first_idx = findLeft(P[right_bug_idx], pos);
        cnt = right_bug_idx - right_first_idx + 1;
        if (cnt >= K) ans = P[right_bug_idx] - pos;
    }
    else if (right_bug_idx == -1)
    {
        int left_last_idx = findRight(P[left_bug_idx], pos);
        cnt = left_last_idx - left_bug_idx + 1;
        if (cnt >= K) ans = pos - P[left_bug_idx];
    }
    else
    {
        cnt = right_bug_idx - left_bug_idx + 1;
        if (cnt >= K)
            ans = P[right_bug_idx] - P[left_bug_idx] +
                  min(P[right_bug_idx] - pos, pos - P[left_bug_idx]);
    }

    if (cnt >= K) return true;
    return false;
}

int main()
{
    ifstream in("ladyin.txt");
    ofstream out("ladyout.txt");
    in >> N >> K >> Q;
    for (int i = 1; i <= N; i++)
    {
        in >> P[i];
        maxp = max(maxp, P[i]);
    }

    while (Q--)
    {
        int pos, ans = INT_MAX;
        in >> pos;
        int l = 1, r = maxp, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (check(pos, mid, ans))
                r = mid - 1;
            else
                l = mid + 1;
        }
        out << ans << " ";
    }

    in.close();
    out.close();
    return 0;
}