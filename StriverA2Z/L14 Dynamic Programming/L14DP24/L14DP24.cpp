#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int bestPrice(int ind, int N, vector<int>& price, vector<vector<int>> &dp) {
    if(ind==0) {
        return N*price[ind];
    }
    if(dp[ind][N]!=-1) return dp[ind][N];
    int notTake = 0 + bestPrice(ind-1,N,price,dp);
    int take = INT_MIN;
    int rodlength = ind+1;
    if(rodlength<=N) take = price[ind] + bestPrice(ind,N-rodlength,price,dp);
    return dp[ind][N] = max(take,notTake);

    // For Recursion:-
    // TC -> Exponential (way greater than O(2^N))
    // SC -> O(target) (auxillary stack-space)

    // For memoization:-
    // TC -> O(N*N)
    // SC -> O(N*N) + O(target)
}

int bestPriceTab(int n,vector<int>price, vector<vector<int>>& dp) {
    for(int N=0; N<=n; N++) dp[0][N] = N*price[0];

    for(int i=1; i<n; i++) {
        for(int N=0; N<=n; N++) {
            int notPick = 0 + dp[i-1][N];
            int pick = INT_MIN;
            int rodLength = i + 1;
            if(rodLength<=N) pick = price[i] + dp[i][N-rodLength];
            dp[i][N] = max(pick,notPick);
        }
    }

    return dp[n-1][n];

    // TC -> O(N*N)
    // SC -> O(N*N)
}

int bestPriceSO1(int n, vector<int>& price) {
    vector<int> prev(n+1,0);
    vector<int> curr(n+1,0);
    for(int N=0; N<=n; N++) prev[N] = N*price[0];

    for(int i=1; i<n; i++) {
        for(int N=0; N<=n; N++) {
            int notPick = 0 + prev[N];
            int pick = INT_MIN;
            int rodLength = i+1;
            if(rodLength<=N) pick = price[i] + curr[N-rodLength];
            curr[N] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[n];
    
    // TC -> O(N*N)
    // SC -> O(2N)
}

int bestPriceSO2(int n, vector<int>& price) {
    vector<int> prev(n+1,0);
    for(int N=0; N<=n; N++) prev[N] = N*price[0];

    for(int i=1; i<n; i++) {
        for(int N=0; N<=n; N++) {
            int notPick = 0 + prev[N];
            int pick = INT_MIN;
            int rodLength = i+1;
            if(rodLength<=N) pick = price[i] + prev[N-rodLength];
            prev[N] = max(pick,notPick);
        }
    }
    return prev[n];

    // TC -> O(N*N)
    // SC -> O(N)
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
    // You are given an rod of length n, and you are given an array that presents the price that you get for each rod-length from n=1 to n=n. So now you have to cut the rod in such a way that you are able to generate the maximum price.

    // We convert this question from cutting to joining and see for what lengths of rod pieces, we are able to form the rod of length n with maximum price.

    int n;
    cin >> n;
    vector<int> price(n);
    for(int i=0; i<n; i++) cin >> price[i];

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n,vector<int>(n+1,-1));
    int bestVal1 = bestPrice(n-1,n,price,dp1);
    cout << bestVal1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n,vector<int>(n+1,0));
    int bestVal2 = bestPriceTab(n,price,dp2);
    cout << bestVal2 << endl;

    // Double-Array Space Optimization Approach:
    int bestVal3 = bestPriceSO1(n,price);
    cout << bestVal3 << endl;

    // Single-Array Space Optimization Approach:
    int bestVal4 = bestPriceSO2(n,price);
    cout << bestVal4 << endl;
    return 0;
}
