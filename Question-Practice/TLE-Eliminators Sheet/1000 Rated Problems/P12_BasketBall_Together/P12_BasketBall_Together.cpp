#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    long long n,d;
    cin >> n >> d;
    vector<long long> p(n);
    for(auto &x: p) cin >> x;
    sort(p.begin(),p.end()); // Sorted the players so as to greedily always pick the largest guy first from the remaining players
    long long r = n-1;
    long long numOfPlayersLeft = n; // Numbers of players left for selection
    long long numOfTeams = 0; // Number of winning teams formed
    while(r>=0) {
        long long maxPower = 0; // MaxPower of team
        for(long long i=1; i<=n; i++) { // Number of players in that team
            if(numOfPlayersLeft==0) break; // If no players left to select, then we can't select
            maxPower = p[r]*i;
            numOfPlayersLeft--; // We selected a player into the team, numOfPlayersLeft thus reduces
            if(maxPower>d) break; // The moment maxPower becomes greater than 0, we stop
        }
        if(maxPower>d) numOfTeams++; // If the break happened because MaxPower becomes more than d, then one more team formed
        else break; // Else the reason for break was that no more players were left to select from.
        r--;
    }
    cout << numOfTeams << endl;
    return 0;
}
