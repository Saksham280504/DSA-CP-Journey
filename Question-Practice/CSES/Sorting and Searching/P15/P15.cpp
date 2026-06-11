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
    multiset<ll> position;
    position.insert(0);
    position.insert(x);
    ll maxGap = LLONG_MIN;
    for(ll i=0; i<n; i++) {
        ll p;
        cin >> p;
        auto it1 = position.upper_bound(p);
        auto it2 = position.lower_bound(p);
        it2--;
        maxGap = max({maxGap,(*it1-p),(p-*it2)});
        cout << maxGap << " ";
    }
    cout << endl;
    return 0;
}
