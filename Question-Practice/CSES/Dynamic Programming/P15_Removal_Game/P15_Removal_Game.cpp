#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

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
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<ll>> dp(n,vector<ll>(n,0LL));
    // dp[i][j] -> maxium possible score possible for 1st player from an array starting from ith index and ending at jth index.
    // The intuition of the problem is that when it's your chance you try to pick the best possible choice, but when its your opponent's chance you always believe that he will pick such that worst case scenario is created for you.
    for(int g=0; g<n; g++) {
        for(int i=0, j=g; j<n; i++,j++) {
            if(g==0) dp[i][j] = arr[i];
            else if(g==1) dp[i][j] = max(arr[i],arr[j]);
            else {
                ll val1 = arr[i] + min(dp[i+2][j],dp[i+1][j-1]);
                ll val2 = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(val1,val2);
            }
        }
    }
    cout << dp[0][n-1] << endl;

    // TC -> O(N^2)

    return 0;
}
