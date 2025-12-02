#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int KJumpDistance(int ind, int k, vector<int>& jumps, vector<int>& dp) {
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int minEnergySteps = INT_MAX;
    for(int j=1; j<=k; j++) {
        if(ind-j>=0) {
            int EnergyTaken = KJumpDistance(ind-j,k,jumps,dp) + abs(jumps[ind]-jumps[ind-j]);
            minEnergySteps = min(minEnergySteps,EnergyTaken);
        }
    }
    return dp[ind] = minEnergySteps;

    // TC -> O(N*K)
    // SC -> O(N) + O(N)
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> jumps(n);
    for(int i=0; i<n; i++) {
        cin >> jumps[i];
    }

    vector<int> dp(n,-1);

    // Memoization Approach:
    // int EnergyTaken = KJumpDistance(n-1,k,jumps,dp);
    // cout << EnergyTaken << endl;

    // Tabulation Approach:
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        int minEnergySteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j>=0) {
                int energyTaken = dp[i-j] + abs(jumps[i]-jumps[i-j]);
                minEnergySteps = min(minEnergySteps, energyTaken);
            }
        }
        dp[i] = minEnergySteps;
    }
    cout << dp[n-1] << endl;
    // TC -> O(N*K)
    // SC -> O(N)

    // Space-optimization is not necessary here, because even after space-optimization, we only get O(K) as our solution, which on worst-case can still result in O(N) solution.

    return 0;
}
