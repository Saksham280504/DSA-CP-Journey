#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<int> dp(x+1,1e9);
    dp[0] = 0;
    for(int sum=1; sum<=x; sum++) {
        for(int j=0; j<n; j++) {
            if(coins[j]<=sum) dp[sum] = min(dp[sum],1+dp[sum-coins[j]]);
        }
    }
    cout << (dp[x] == 1e9? -1 : dp[x]) << endl;

    return 0;
}
