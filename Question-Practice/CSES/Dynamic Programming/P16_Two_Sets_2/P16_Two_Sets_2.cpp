#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long 

const ll mod = 1e9+7;

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
    int TotalSum = n*(n+1)/2;

    if(TotalSum&1) {
        cout << 0 << endl;
        return 0;
    }

    int TargetSum = TotalSum/2;

    vector<ll> dp(TargetSum+1,0);
    dp[0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=TargetSum; j>=i; j--) {
            dp[j] = (dp[j] + dp[j-i])%mod;
        }
    }

    // Since each partition is counted twice, we divide by 2.
    // To handle division under modulo, we multiply modular inverse of 2.
    ll inverse_2 = 500000004;
    cout << (dp[TargetSum]*inverse_2)%mod << endl;

    return 0;
}
