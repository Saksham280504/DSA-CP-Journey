#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
using ll = long long;
void solve() {
    ll x,n;
    cin >> x >> n;
    if(x%2==0) {
        if(n%4==0) x = x;
        else if(n%4==1) x -= n;
        else if(n%4==2) x += 1;
        else x += n+1;
    }
    else {
        if(n%4==0) x = x;
        else if(n%4==1) x += n;
        else if(n%4==2) x -= 1;
        else x -= n+1;
    }
    cout << x << endl;
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
