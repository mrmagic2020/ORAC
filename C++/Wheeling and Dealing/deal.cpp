#include <algorithm>
#include <climits>
#include <fstream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
#define x first   // Cost x to bribe
#define y second  // Vote for candidate y
#define rep(i, n) for (int i = 0; i < (n); i++)

int N, M;

int main()
{
    ifstream in("dealin.txt");
    ofstream out("dealout.txt");
    in >> N >> M;
    vector<pii> voters(M);
    rep(i, M)
    {
        in >> voters[i].second;
        voters[i].second--;  // zero-index the candidates
    }
    rep(i, M) in >> voters[i].first;
    sort(voters.begin(), voters.end());  // sort voters by cost (first element)

    // voters_for[i] stores voters_for voting for candidate i in increasing
    // order of cost
    vector<queue<int>> voters_for(N);
    rep(i, M) voters_for[voters[i].second].push(i);

    // sotres for each candidate (except candidate 1) the number of voters they
    // have
    // first - the number of votes
    // second - the candidate id
    set<pii> numvotes;
    for (int i = 1; i < N; i++) numvotes.insert({voters_for[i].size(), i});

    // Stores the number of voters bought off in step 1.
    int numbought = 0;

    // of the voters that haven't been bought off in step 1 yet:
    // - payroll stores the minimum set of voters we need to win
    // - pool stores the remaining voters we might want in the future
    set<pii> payroll;
    set<pii> pool;
    rep(i, M) if (voters[i].second != 0) pool.insert({voters[i].first, i});

    // Test every X.
    int best = INT_MAX;
    int step1cost = 0;
    int step2cost = 0;
    for (int X = M - 1; X >= 0; X--)
    {
        // Step 1 - buy off people until all candidates are at most X.

        // repeatedly find the candidate with most votes, and but off their next
        // cheapest member.
        while (numvotes.rbegin()->first > X)
        {
            // obtain the cheapest voter for this candidate
            int candidate = numvotes.rbegin()->second;
            int to_buy = voters_for[candidate].front();
            voters_for[candidate].pop();
            int bribe_cost = voters[to_buy].first;

            numbought++;
            step1cost += bribe_cost;

            // remove this person from the payroll/pool
            pool.erase({bribe_cost, to_buy});
            if (payroll.count({bribe_cost, to_buy}))
            {
                payroll.erase({bribe_cost, to_buy});
                step2cost -= bribe_cost;
            }

            // reduce the size of this candidate by 1
            pii el = *numvotes.rbegin();
            numvotes.erase(el);
            numvotes.insert({el.first - 1, el.second});
        }

        // Step 2 - work out which voters we should buy off to get candidate 1
        // above X

        int curr_votes = voters_for[0].size() + numbought;
        int votes_required = max((X + 1) - curr_votes, 0);

        // set is too small. move unbought voters from the pool into the
        // payroll.
        while (payroll.size() < votes_required)
        {
            // Note: it should never be possible for there to be no voters in
            // the pool and for candidate 1 to still be losing.
            int cheapest = pool.begin()->second;
            pool.erase(pool.begin());
            payroll.insert({voters[cheapest].first, cheapest});
            step2cost += voters[cheapest].x;
        }
        // set is too large. move the most expansive voters back into the pool.
        while (payroll.size() > votes_required)
        {
            // put them back into the pool
            int most_expensive = payroll.rbegin()->second;
            payroll.erase(prev(payroll.end()));
            pool.insert({voters[most_expensive].first, most_expensive});
            step2cost -= voters[most_expensive].first;
        }

        int total_cost = step1cost + step2cost;
        best = min(best, total_cost);
    }

    out << best << endl;

    in.close();
    out.close();
    return 0;
}