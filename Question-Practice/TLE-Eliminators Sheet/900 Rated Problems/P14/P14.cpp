#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define endl '\n'

void solve() {
    ll n;
    cin >> n;
    bool isMinPossible = true;
    bool isMaxPossible = true;
    // For Minimum Number of buses

    ll remaining1 = n%6;
    ll MinBuses = n/6;
    if(remaining1%4!=0) isMinPossible = false;
    else if(remaining1!=0) MinBuses += 1;

    // For Maximum Number of buses

    ll remaining2 = n%4;
    ll MaxBuses = n/4;
    if(remaining2!=0) isMaxPossible = false;

    if(isMinPossible==false && isMaxPossible== false) cout << -1 << endl;
    else if(isMinPossible==false) cout << MaxBuses << " " << MaxBuses << endl;
    else if(isMaxPossible==false) cout << MinBuses << " " << endl;
    else cout << MinBuses << " " << MaxBuses << endl;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}