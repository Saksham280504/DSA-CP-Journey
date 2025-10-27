#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxBursts(int i, int j, vector<int>& bursts, vector<vector<int>>& dp) {
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int maxi = -1e9;
    for(int ind=i; ind<=j; ind++) {
        int val = bursts[i-1]*bursts[ind]*bursts[j+1] + maxBursts(i,ind-1,bursts,dp) + maxBursts(ind+1,j,bursts,dp);
        maxi = max(maxi,val);
    }
    return dp[i][j] = maxi;

    // Recursive Approach:
    // TC -> Exponential

    // Memoization Approach:
    // TC -> O(N*N)*N -> O(N^3)
    // SC -> O(N*N) + O(N) (Auxillary Stack Space)
}

int maxBurstsTab(int n, vector<int>& bursts, vector<vector<int>>& dp) {

    for(int i=n; i>=1; i--) {
        for(int j=i; j<=n; j++) {
            int maxi = -1e9;
            for(int ind=i; ind<=j; ind++) {
                int val = bursts[i-1]*bursts[ind]*bursts[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi,val);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
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
    vector<int> bursts(n);
    for(int i=0; i<n; i++) cin >> bursts[i];

    bursts.push_back(1);
    bursts.insert(bursts.begin(),1);

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
    int maxVal1 = maxBursts(1,n,bursts,dp1);
    cout << maxVal1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+2,vector<int>(n+2,0)); // Handled the base-case (i>j)
    int maxVal2 = maxBurstsTab(n,bursts,dp2);
    cout << maxVal2 << endl;

    return 0;
}
