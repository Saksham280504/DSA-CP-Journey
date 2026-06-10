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
    vector<ll> weight(n);
    for(ll i=0; i<n; i++) cin >> weight[i];
    sort(weight.begin(), weight.end());

    ll l=0, r=n-1, gandolas = 0;

    while(l<=r) {
        if(l==r) {
            gandolas++;
            break;
        }
        if((weight[l] + weight[r])<=x) {
            l++;
            r--;
        }
        else r--;
        gandolas++;
    }

    cout << gandolas << endl;

    return 0;
}
