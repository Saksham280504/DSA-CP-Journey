#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
using ll = long long;

void isSurvivalPossible(ll n, ll k) {
    vector<ll> h(n);

    for(ll i=0; i<n; i++) {
        cin >> h[i];
    }
    ll height = h[k-1];
    ll index;

    sort(h.begin(), h.end());

    for(ll i=0; i<n; i++) {
        if(h[i]==height) {
            index = i;
            break;
        }
    }

    ll waterLevel = 1;
    ll timeGap = h[index]-waterLevel+1;

    for(ll i = index+1; i<n; i++) {
        if((h[i]-h[index])<=timeGap) {
            index = i;
            if(h[index]==h[n-1]) {
                cout << "YES" << endl;
                return;
            }
            waterLevel += (h[i]-h[index]);
            timeGap = h[index]-waterLevel+1;
            continue;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;

    for(ll i=0; i<t; i++) {
        ll n, k;
        cin >> n >> k;
        isSurvivalPossible(n,k);
    }

    return 0;
}
