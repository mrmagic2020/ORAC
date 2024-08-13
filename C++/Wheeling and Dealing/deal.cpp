#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int N, M, ans;
vector<int> tmpCdd;
unordered_set<int> cddCnt;
vector<priority_queue<int, vector<int>, greater<int>>> votes;

bool sortCdd(priority_queue<int, vector<int>, greater<int>> a,
             priority_queue<int, vector<int>, greater<int>> b)
{
    return !a.empty() && (!b.empty() ? a.size() == b.size() ? a.top() < b.top() : a.size() > b.size() : true);
}

int getMaxVoted()
{
    int res = 0;
    for (int i = 2; i <= N; i++)
    {
        res = max(res, (int)votes[i].size());
    }
    return res;
}

void printVotes()
{
    for (int i = 1; i <= N; i++)
    {
        printf("Votes for candidate %d: ", i);
        auto cpy = votes[i];
        while (!cpy.empty())
        {
            printf("%d ", cpy.top());
            cpy.pop();
        }
        puts("");
    }
}

int main()
{
    ifstream in("dealin.txt");
    in >> N >> M;
    tmpCdd.resize(M + 1);
    votes.resize(N + 1);
    cddCnt.insert(1);
    for (int i = 1, cdd; i <= M; i++)
    {
        in >> cdd;
        tmpCdd[i] = cdd;
        cddCnt.insert(cdd);
    }
    for (int i = 1, cdd = 1, bribe; i <= M; i++)
    {
        in >> bribe;
        votes[tmpCdd[i]].push(bribe);
    }

    sort(votes.begin() + 2, votes.end(), sortCdd);
    int idx = 2;
    while (votes[1].size() <= getMaxVoted())
    {
        while (votes[idx].empty() && idx <= N) idx++;
        if (idx > N) break;
        ans += votes[idx].top();
        votes[1].push(votes[idx].top());
        votes[idx].pop();
        sort(votes.begin() + 2, votes.end(), sortCdd);
    }
    // for (int i = 2; i <= N; i++)
    // {
    //     while (votes[i].size() >= votes[1].size())
    //     {
    //         ans += votes[i].top();
    //         votes[1].push(votes[i].top());
    //         votes[i].pop();
    //     }
    // }

    // const int targetVotes = M / cddCnt.size() + 1;
    // printf("Target votes: %d\n", targetVotes);
    // for (int i = 2; i <= N; i++)
    // {
    //     printf("Inspecting voters for candidate %d.\n", i);
    //     while (votes[i].size() >= targetVotes)
    //     {
    //         printf("Bribing voter for candidate %d with $%d.\n", i,
    //                votes[i].top());
    //         ans += votes[i].top();
    //         votes[1].push(votes[i].top());
    //         votes[i].pop();
    //     }
    // }
    // if (votes[1].size() < targetVotes)
    // {
    //     sort(votes.begin() + 2, votes.end(), sortCdd);
    //     printVotes();
    //     int idx = 2;
    //     while (votes[1].size() < targetVotes)
    //     {
    //         while (votes[idx].empty() && idx <= N) idx++;
    //         if (idx > N) break;
    //         votes[1].push(votes[idx].top());
    //         ans += votes[idx].top();
    //         printf("Spent an additional $%d at index %d. Voter 1 now has %zu
    //         votes.\n", votes[idx].top(), idx, votes[1].size());
    //         votes[idx].pop();
    //     }
    // }

    ofstream out("dealout.txt");
    out << ans << endl;
    return 0;
}