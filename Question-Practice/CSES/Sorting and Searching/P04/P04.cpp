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
    ll n,m;
    cin >> n >> m;
    vector<ll> price(n);
    for(ll i=0; i<n; i++) cin >> price[i];
    sort(price.rbegin(),price.rend());
    vector<pair<ll,ll>> maxPrice(m);
    for(ll i=0; i<m; i++) {
        ll cost;
        cin >> cost;
        maxPrice.push_back({cost,i});
    }
    sort(maxPrice.rbegin(), maxPrice.rend());

    ll l=0, r=0;
    vector<ll> ans(m,-1);

    while(l<n && r<m) {
        if(price[l]>maxPrice[r].first) l++;
        else { // first occurance of price[l] <= maxPrice[r].first
            ans[maxPrice[r].second] = price[l];
            r++;
            l++;
        }
    }

    for(ll i=0; i<m; i++) {
        cout << ans[i] << endl;
    }


    return 0;
}
