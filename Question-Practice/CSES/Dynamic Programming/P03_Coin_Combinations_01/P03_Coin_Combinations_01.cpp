#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

const int_least64_t mod = 1e9 + 7;

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
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int sum=1; sum<=x; sum++) {
        for(int j=0; j<n; j++) {
            if(coins[j]<=sum) {
                dp[sum] = (dp[sum]+dp[sum-coins[j]])%mod;
            }
        }
    }
    cout << dp[x] << endl;

    // Don't use ll here, as that will give TLE due to slower arithematic and doubles memory usage.
    return 0;
}
