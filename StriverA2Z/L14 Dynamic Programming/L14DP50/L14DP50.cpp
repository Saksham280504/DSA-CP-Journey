#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int minCuts(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    for(int ind=i; ind<=j; ind++) {
        int cost = cuts[j+1] - cuts[i-1] + minCuts(i,ind-1,cuts,dp) + minCuts(ind+1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] = mini;

    // For recursive approach, TC-> Exponential

    // For Memoization APproach, TC-> O(c^2)*c -> O(c^3)
    // SC -> O(C^2) + Auxillary Stack Space
}

int minCutsTab(int c, vector<int>& cuts, vector<vector<int>>& dp) {

    for(int i=c; i>=1; i--) {
        for(int j=i; j<=c; j++) {
            int mini = 1e9;
            for(int ind=i; ind<=j; ind++) {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][c];
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

    int c;
    cin >> c;
    vector<int> cuts;
    for(int i=0; i<c; i++) {
        int nums;
        cin >> nums;
        cuts.push_back(nums);
    }

    int n;
    cin >> n;
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());

    // Recursive/Memoization Solution:
    vector<vector<int>> dp1(c+1,vector<int>(c+1,-1));
    int mini1 = minCuts(1,c,cuts,dp1);
    cout << mini1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(c+2,vector<int>(c+2,0)); // Base-Case (i>j) handled in declaration
    int mini2 = minCutsTab(c,cuts,dp2);
    cout << mini2 << endl;
    return 0;
}
