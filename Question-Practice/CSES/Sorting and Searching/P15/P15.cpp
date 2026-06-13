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
    ll x,n;
    cin >> x >> n;
    set<ll> pos;
    multiset<ll> plens; // passage length
    pos.insert(0);
    pos.insert(x);
    plens.insert(x);

    for(ll i=0; i<n; i++) {
        ll y;
        cin >> y;
        auto right = pos.upper_bound(y);
        auto left = right;
        left--;
        ll r = *right;
        ll l = *left;
        plens.erase(plens.find(r-l)); // First find (r-l) and then remove it. Doing it this way will remove only one occurance of (r-l) in plens. Otherwise erasing it directly would have removed all the occurances which we don't want.
        plens.insert((r-y));
        plens.insert((y-l));
        pos.insert(y);
        cout << *plens.rbegin() << " ";
    }
    cout << endl;


    return 0;
}
