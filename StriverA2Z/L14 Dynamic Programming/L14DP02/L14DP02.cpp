#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int ClimbingStairs(int ind, vector<int>& dp) {
    // Normal way
    // if(ind<=1) return 1;
    // int left = ClimbingStairs(ind-1);
    // int right = ClimbingStairs(ind-2);
    // return left+right;

    // Memoization:
    if(ind<=1) return 1;
    if(dp[ind]!=-1) return dp[ind];
    else return dp[ind] = ClimbingStairs(ind-1,dp) + ClimbingStairs(ind-2,dp);
    // TC -> O(N)
    // SC -> O(2N)
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

    // How do we know that the given problem is a DP problem?

    // 1. Count the total number of ways
    // 2. Multiple ways to do anything, but we want the way that generates the minimum/maximum output
    // Whenver there is a problem where you need to apply and try all the possible ways, either in order to get the count or the best/worst way, that's when you apply recursion, and this created the base-condition for DP problems.

    // Shortcut: 
    // Try to represent the problem in terms of index.
    // Do all possible stuffs on that index according to the problem statement.
    // Sum of all stuffs -> count all ways
    // min of all stuffs -> find min 

    // Solution:

    int n;
    cin >> n;
    vector<int> dp(n+1,-1);

    // Recursive Approach
    // int numOfWays = ClimbingStairs(n,dp);
    // cout << numOfWays << endl;

    // This problem is same as Fibonacci problem, where we need to apply recursion to calculate the number of ways to reach 0 (i.e. the base-case).

    // Tabulation Approach: SC(N) approach

    // dp[0] = 1;
    // dp[1] = 1;
    // for(int i=2; i<=n; i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout << dp[n] << endl;

    // TC -> O(N)
    // SC -> O(1)

    // Tabulation Approach: SC(1) approach

    int prev2 = 1;
    int prev = 1;
    int curi = -1;
    for(int i = 2; i<=n; i++) {
        curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    } 
    cout << prev << endl;
    // TC -> O(N)
    // SC -> O(1)

    return 0; 
}
