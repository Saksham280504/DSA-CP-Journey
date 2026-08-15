#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
ll mod = 1e9+7;

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
    ll bitStrings = 1;
    for(int i=1; i<=n; i++) {
        bitStrings = ((bitStrings%mod)*(2%mod))%mod;
        // (a*b)%mod = ((a%mod)*(b%mod))%mod
    }
    cout << bitStrings << endl;

    return 0;
}
