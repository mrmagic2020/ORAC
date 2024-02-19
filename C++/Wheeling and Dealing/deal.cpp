#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Voter
{
    int vote, money;
    Voter() : vote(0), money(0) {}
    Voter(int vote, int money) : vote(vote), money(money) {}
};

int N, M;
vector<int> cnt;
vector<Voter> votes;
vector<vector<int>> record; // index is the candidate number

bool sortByMoney(Voter a, Voter b)
{
    return a.money < b.money;
}

int main()
{
    ifstream fin("dealin.txt");
    fin >> N >> M;
    cnt.resize(N + 1, 0);
    votes.resize(M + 1);
    record.resize(N + 1);
    for (int i = 1; i <= M; i++)
    {
        Voter v = Voter();
        fin >> v.vote;
        votes[i] = v;
        cnt[v.vote]++;
        cout << v.vote << " ";
    }
    cout << endl;
    for (int i = 1; i <= M; i++)
    {
        fin >> votes[i].money;
        cout << votes[i].money << " ";
    }
    cout << endl;
    fin.close();

    // transform();
    // print_record();

    sort(votes.begin(), votes.end(), sortByMoney);

    int ans = 0;
    for (int i = 1; i <= M; i++)
    {
        if (votes[i].vote == 1) continue;
        if (cnt[votes[i].vote] < cnt [1]) continue;

        cnt[votes[i].vote]--;
        cnt[1]++;
        ans += votes[i].money;
        printf("Transferring vote %d to 1 using $%d. %d votes for %d, %d votes for 1.\n", votes[i].vote, votes[i].money, cnt[votes[i].vote], votes[i].vote, cnt[1]);
    }

    ofstream fout("dealout.txt");
    fout << ans << endl;
    fout.close();
    
    return 0;
}