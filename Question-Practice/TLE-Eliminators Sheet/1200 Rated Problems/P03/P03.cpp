#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
ll lcm(ll x, ll y) {
    return x*y/__gcd(x,y);
}

ll calculateSum(ll start, ll end) {
    return ((end+start)*(end-start+1)/2);
}
void solve() {
    ll n,x,y;
    cin >> n >> x >> y;
    ll ndivx = n/x - n/lcm(x,y);
    ll ndivy = n/y - n/lcm(x,y);
    ll sum1 = calculateSum(n-ndivx+1,n);
    ll sum2 = calculateSum(1,ndivy);
    cout << sum1-sum2 << endl;

    // TC -> O(logN)
}

int main() {
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
