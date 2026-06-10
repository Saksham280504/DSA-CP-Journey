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
    ll n,x;
    cin >> n >> x;
    unordered_map<ll,vector<ll>> mpp;
    for(ll i=0; i<n; i++) {
        ll y;
        cin >> y;
        mpp[y].push_back(i+1);
    }

    for(auto it: mpp) {
        if(mpp.count(x-it.first)) {
            if(it.first!=x/2) {
                cout << it.second[0] << " " << mpp[x-it.first][0] << endl;
                return 0;
            }
            else {
                if(it.second.size()>1) {
                    cout << it.second[0] << " " << it.second[1] << endl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
