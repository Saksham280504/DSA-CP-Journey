#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int bestValue(int ind, int w, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp) {
    if(ind==0) {
        // if(weight[ind]<=w) return value[ind] + bestValue(ind,w-weight[ind],weight,value,dp); // This is okay but we can reduce the number of recursion calls by using simple Mathematics
        if(weight[ind]<=w) return value[ind]*(w/weight[ind]);
        return 0;
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notPick = 0 + bestValue(ind-1,w,weight,value,dp);
    int pick = INT_MIN;
    if(weight[ind]<=w) pick = value[ind] + bestValue(ind,w-weight[ind],weight,value,dp);
    return dp[ind][w] = max(notPick,pick);

    // Recursive Approach:
    // TC -> Exponential (way greater than O(2^n))
    // SC -> O(W) // recursive stack space depends upon the W

    // Memoization Approach:
    // TC -> O(N*W)
    // SC -> O(W) + O(N*W)
}

int BestValueTab(int n, int w, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp) {
    for(int wt=weight[0]; wt<=w; wt++) dp[0][wt] = (value[0]*(wt/weight[0]));
    
    for(int i=1; i<n; i++) {
        for(int wt=0; wt<=w; wt++) {
            int notPick = 0 + dp[i-1][wt];
            int pick = INT_MIN;
            if(weight[i]<=wt) pick = value[i] + dp[i][wt-weight[i]];
            dp[i][wt] = max(pick, notPick);
        }
    }

    return dp[n-1][w];

    // TC -> O(N*W)
    // SC -> O(N*W)
}

int bestValueSO(int n, int w, vector<int>& weight, vector<int>& value) {
    vector<int> prev(w+1, 0);
    vector<int> curr(w+1, 0);
    for(int wt=weight[0]; wt<=w; wt++) prev[wt] = (value[0]*(wt/weight[0]));

    for(int i=1; i<n; i++) {
        for(int wt=0; wt<=w; wt++) {
            int notPick = 0 + prev[wt];
            int pick = INT_MIN;
            if(weight[i]<=wt) pick = value[i] + curr[wt-weight[i]];
            curr[wt] = max(pick, notPick);
        }
        prev = curr;
    }

    return prev[w];

    // TC -> O(N*W)
    // SC -> O(2W)
}

int bestValueSO2(int n, int w, vector<int>& weight, vector<int>& value) {
    vector<int> prev(w+1,0);

    for(int wt=weight[0]; wt<=w; wt++) prev[wt] = (value[0]*(wt/weight[0]));

    for(int i=1; i<n; i++) {
        for(int wt=0; wt<=w; wt++) {
            int notPick = 0 + prev[wt];
            int pick = INT_MIN;
            if(weight[i]<=wt) pick = value[i] + prev[wt-weight[i]];
            prev[wt] = max(pick, notPick);
        }
    }

    return prev[w];

    // TC -> O(N*W)
    // SC -> O(W)
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
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0; i<n; i++) cin >> weight[i];
    for(int i=0; i<n; i++) cin >> value[i];
    int w;
    cin >> w;

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n, vector<int>(w+1,-1));
    int best1 = bestValue(n-1,w,weight,value,dp1);
    cout << best1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n,vector<int>(w+1,0));
    int best2 = BestValueTab(n,w,weight,value,dp2);
    cout << best2 << endl;

    // SO (Double-Array Approach):
    int best3 = bestValueSO(n,w,weight,value);
    cout << best3 << endl;

    // SO (Single-Array Approach):
    int best4 = bestValueSO2(n,w,weight,value);
    cout << best4 << endl;

    return 0;
}
