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

    ll n,m,k;
    cin >> n >> m >> k;
    vector<pair<ll,ll>> desired_appartments;
    for(ll i=0; i<n; i++) {
        ll x;
        cin >> x;
        desired_appartments.push_back({x-k,x+k});
    }

    sort(desired_appartments.begin(),desired_appartments.end());

    vector<ll> appartments(m);
    for(ll i=0; i<m; i++) {
        cin >> appartments[i];
    }

    sort(appartments.begin(),appartments.end());

    ll l=0,r=0;
    ll cnt = 0;

    while(l<n && r<m) {
        if(desired_appartments[l].first<=appartments[r] && appartments[r]<=desired_appartments[l].second ) {
            cnt++;
            l++;
            r++;
        }
        else if(appartments[r]<desired_appartments[l].first) r++;
        else l++;
    }

    cout << cnt << endl;

    return 0;
}
