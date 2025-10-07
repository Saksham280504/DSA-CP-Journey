#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int BestValue(int ind, int w, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp) {
    // BestValue(n-1,w) -> Till the index n-1, what maximum value can the thief get for a bag-weight of w

    if(ind==0) {
        if(weight[ind]<=w) return value[ind];
        else return 0;
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notTake = 0 + BestValue(ind-1,w,weight,value,dp);
    int take = INT_MIN;
    if(weight[ind]<=w) take = value[ind] + BestValue(ind-1,w-weight[ind],weight,value,dp);

    return dp[ind][w] = max(take,notTake);

    // Recursive Approach:
    // TC -> O(2^n)
    // SC -> O(N)

    // Memoization Approach:
    // TC -> O(N*W)
    // SC -> O(N)(recursive stack space) + O(N*W) (dp-array)
}

int bestTab(int n, int w, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp) {
    for(int wt=weight[0]; wt<=w; wt++) dp[0][wt] = value[0];

    for(int i=1; i<n; i++) {
        for(int wt = 0; wt<=w; wt++) {
            int notTake = 0 + dp[i-1][wt];
            int take = INT_MIN;
            if(weight[i]<=wt) take = value[i] + dp[i-1][wt-weight[i]];
            dp[i][wt] = max(notTake,take);
        }
    }
    return dp[n-1][w];

    // TC -> O(N*W)
    // SC -> O(N*W)
}

int bestSO(int n, int w, vector<int>& weight, vector<int>& value) {
    vector<int> prev(w+1,0);
    vector<int> curr(w+1,0);
    for(int wt=weight[0]; wt<=w; wt++) prev[wt] = value[0];

    for(int i=1; i<n; i++) {
        for(int wt=0; wt<=w; wt++) {
            int notPick = 0 + prev[wt];
            int pick = INT_MIN;
            if(weight[i]<=wt) pick = value[i] + prev[wt-weight[i]];
            curr[wt] = max(notPick, pick);
        }
        prev = curr;
    }

    return prev[w];

    // TC -> O(N*W)
    // SC -> O(2W)
}

int bestSO2(int n, int w, vector<int>& weight, vector<int>& value) {
    vector<int> prev(w+1,0);
    for(int wt=weight[0]; wt<=w; wt++) prev[wt] = value[0];

    for(int i=1; i<n; i++) {
        for(int wt=w; wt>=0; wt--) {
            int notPick = 0 + prev[wt];
            int pick = INT_MIN;
            if(weight[i]<=wt) pick = value[i] + prev[wt-weight[i]];
            prev[wt] = max(notPick, pick);
        }
    }

    return prev[w];

    // TC -> O(N*W)
    // SC -> O(W)
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // This video is not there on the website due to some glitch. So to find the video for this lecture, search: "DP 19. 0/1 Knapsack | Recursion to Single Array Space Optimised Approach | DP on Subsequences"

    // You are a thief and you have to rob a house, which has a series of n items having certain value and weight. You have a bag which you use to carry the items and it has a target weight which is the maximum weight it can carry. So, now as a thief you have to steal the most value out of the house.

    int n;
    cin >> n;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0; i<n; i++) cin >> weight[i];
    for(int i=0; i<n; i++) cin >> value[i];
    int w;
    cin >> w;

    // Greedy Algorithm is not applicable because there is no uniformity in the input, you are not sure what is the best output for you until you try out all the paths. This means we need to go for the recursion solution.

    // Recursion/Memoization Approach:
    vector<vector<int>> dp1(n, vector<int>(w+1,-1));
    int best1 = BestValue(n-1, w, weight, value,dp1);
    cout << best1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n,vector<int>(w+1,0));
    int best2 = bestTab(n,w, weight, value, dp2);
    cout << best2 << endl;

    // Space-optimization Approach (Double Array approach):
    int best3 = bestSO(n,w,weight,value);
    cout << best3 << endl;

    // Space-Optimization Approach (Single Array approach):

    int best4 = bestSO2(n,w, weight, value);
    cout << best4 << endl;

    return 0;
}