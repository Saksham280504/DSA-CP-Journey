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
    ll n;
    cin >> n;
    vector<ll> cubes(n);
    for(ll i=0; i<n; i++) cin >> cubes[i];
    multiset<ll> towers;
    towers.insert(cubes[0]);

    for(ll i=1; i<n; i++) {
        auto it = towers.upper_bound(cubes[i]);
        if(it!=towers.end()) towers.erase(it);
        towers.insert(cubes[i]);
    }

    cout << towers.size() << endl;

    return 0;
}
