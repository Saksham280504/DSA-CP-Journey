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
    ll n,k,x;
    cin >> n >> k >> x;
    if(n==1) {
        cout << 1 << endl;
        return 0;
    }
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll cnt = 0;
    vector<ll> diff;
    for(ll i=1; i<n; i++) {
        if(a[i]-a[i-1]>x) {
            cnt++;
            diff.push_back(a[i]-a[i-1]);
        }
    }
    cnt++;

    sort(diff.begin(), diff.end());
    ll ind = 0;
    ll m = diff.size();
    while(k>0 && cnt>1 && ind<m) {
        if(k<diff[ind]/x) break;
        k -= diff[ind]/x;
        cnt--;
        ind++;
    }
    cout << cnt << endl;

    return 0;
}
