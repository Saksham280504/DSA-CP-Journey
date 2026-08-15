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
    for(ll k=1; k<=n; k++) {
        ll totalPairs = ((k*k)*((k*k)-1))/2; // k*k are the total positions so we simply did -> (total Positions)c2;
        ll notAcceptedPairs = (k-1)*(k-2)*2*2; // We just find how many 2*3 and 3*2 slabs exists within the grid and that is (k-1)*(k-2)*2 and in each slab there are 2 not acceptable positions thus we multiply by 2 again.
        cout << (totalPairs-notAcceptedPairs) << endl;
    }

    return 0;
}
