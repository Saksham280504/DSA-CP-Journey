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
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> b;
    for(ll i=1; i<n; i++) {
        if(a[i]-a[i-1]>x) {
            b.push_back(a[i]-a[i-1]);
        }
    }

    sort(b.begin(), b.end());

    ll ans = b.size()+1;

    for(auto diff: b) {
        ll val = (diff/x) + (diff%x!=0)-1;
        if(k>=val) {
            ans--;
            k-=val;
        }
    }

    cout << ans << endl;

    return 0;
}
