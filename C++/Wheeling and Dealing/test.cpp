#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ifstream in("dealin.txt");
    int N, M;
    in >> N >> M;

    vector<int> voteCounts(N + 1, 0);
    vector<priority_queue<int, vector<int>, greater<int>>> bribes(N + 1);

    // Read voters' initial choices
    vector<int> initialVotes(M);
    for (int i = 0; i < M; ++i) {
        in >> initialVotes[i];
        voteCounts[initialVotes[i]]++;
    }

    // Read bribes
    for (int i = 0; i < M; ++i) {
        int bribe;
        in >> bribe;
        bribes[initialVotes[i]].push(bribe);
    }

    // Calculate the number of votes candidate 1 needs to win
    int votesNeeded = *max_element(voteCounts.begin() + 2, voteCounts.end()) - voteCounts[1] + 1;
    int totalBribes = 0;

    if (votesNeeded > 0) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 2; i <= N; ++i) {
            while (!bribes[i].empty()) {
                pq.push(bribes[i].top());
                bribes[i].pop();
            }
        }

        for (int i = 0; i < votesNeeded && !pq.empty(); ++i) {
            totalBribes += pq.top();
            pq.pop();
        }
    }

    ofstream out("dealout.txt");
    out << totalBribes << endl;

    return 0;
}