#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


// The core intuition behind the problem is that this is a miniMax dp on states problem. There are 2 states (ind,M). 
// dp[ind][M] -> Maximum numbers of stones retrievable starting from ind with cap M
// If at index i, remaining stones are suffixSum[i]
// Then the maximum stones that the opponent can get is dp(i+x,max(M,x))
// So the current player will have suffixSum[i]-opponent
// Compare for all values of x (1<=x<=2*M), and store the maximum current value
// If you are able to take all the remaining piles then return suffixSum[i]
class Solution {
public:
    int n;
    vector<int> suffixSum;
    vector<vector<int>> dp;
    int solve(int ind, int M, vector<int>& piles) {
        // No more piles left
        if(ind>=n) return 0;

        // All piles can be taken
        if(ind+2*M>=n) return suffixSum[ind];

        if(dp[ind][M]!=-1) return dp[ind][M];

        int ans = 0;
        for(int x=1; x<=2*M; x++) {
            // Opponent
            int Opponent = solve(ind+x,max(M,x),piles);
            int current = suffixSum[ind] - Opponent;
            ans = max(ans,current);
        }

        return dp[ind][M] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.resize(n);
        suffixSum[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--) {
            suffixSum[i] = piles[i] + suffixSum[i+1];
        }
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,1,piles);
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
