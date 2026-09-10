#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
ll mod = 1e9+7;

ll power(ll base, ll exp) {
    if(exp==0) return 1;
    ll res = 1;
    while(exp) {
        if(exp&1) res = ((res%mod)*(base%mod))%mod;
        base = ((base%mod)*(base%mod))%mod;
        exp >>= 1;
    }
    return res;
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
    ll n;
    cin >> n;

    // Approach - 1
    // ll bitStrings = 1;
    // for(int i=1; i<=n; i++) {
    //     bitStrings = ((bitStrings%mod)*(2%mod))%mod;
    //     // (a*b)%mod = ((a%mod)*(b%mod))%mod
    // }
    // cout << bitStrings << endl;

    // Approach-2 (Logarithmic Exponentiation)
    cout << power(2LL,n) << endl;

    return 0;
}
