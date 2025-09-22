#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n' 
int FrogJump(int ind, vector<int>& jump, vector<int>& dp) {
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int right = INT_MAX;
    int left = FrogJump(ind-1,jump,dp) + abs(jump[ind]-jump[ind-1]);
    if(ind>1) right = FrogJump(ind-2,jump,dp) + abs(jump[ind]-jump[ind-2]);
    return dp[ind] = min(left,right);

    // TC -> O(N)
    // SC -> O(N) (stack-space) + O(N) (dp-array)
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

    // Our approach for this problem will be as follows:
    // 1. Express the problem in terms of index 
    // 2. Do all stuffs on that index
    // 3. Take the minimum value of all stuffs

    int n;
    cin >> n;
    vector<int> jump(n);
    for(int i=0; i<n; i++) {
        cin >> jump[i];
    }

    // Memoization Approach:
    // vector<int> dp(n+1,-1);
    // int cnt = FrogJump(n-1,jump,dp);
    // cout << cnt << endl;

    // Tabulation Approach:
    // vector<int> dp(n+1,-1);
    // dp[0] = 0;
    // for(int i=1; i<n; i++) {
    //     int fs = dp[i-1] + abs(jump[i]-jump[i-1]);
    //     int ss = INT_MAX;
    //     if(i>1) ss = dp[i-2] + abs(jump[i]-jump[i-2]);
    //     dp[i] = min(ss,fs);
    // }

    // cout << dp[n-1] << endl;

    // TC -> O(N)
    // SC -> O(N)

    int prev = 0;
    int prev2 = 0;
    int curi = -1;
    for(int i=1; i<n; i++) {
        int fs = prev + abs(jump[i]-jump[i-1]);
        int ss = INT_MAX;
        if(i>1) ss = prev2 + abs(jump[i]-jump[i-2]);
        curi = min(fs,ss);

        prev2 = prev;
        prev = curi;
    }

    cout << curi << endl;
    return 0;
}
