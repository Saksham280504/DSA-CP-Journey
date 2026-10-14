#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int totalWays = 1<<n;
        vector<pair<int,int>> dp(totalWays,{n+1,0});
        // dp[mask] -> {minimum number of sessions, current session time used}
        dp[0] = {1,0}; // you are about to start your first task, hence first session has started
        for(int mask=0; mask<totalWays; mask++) {
            for(int i=0; i<n; i++) {
                if(!mask&(1<<i)) {
                    int newMask = mask | (1<<i);
                    pair<int,int> newState;
                    if(dp[mask].second+tasks[i]<=sessionTime) newState = {dp[mask].first,dp[mask].second+tasks[i]};
                    else newState = {dp[mask].first+1,tasks[i]};
                    if(newState<dp[newMask]) dp[newMask] = newState; // first priority is to get lexographically minimum number of sessions, if that is same then the session with minimum time used
                }
            }
        }
        return dp[totalWays-1].first;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
