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
    ll total = (n*(n+1))/2;
    if(total&1) {
        cout << "NO" << endl;
        return 0;
    }

    ll target = total/2;
    vector<ll> arr1, arr2;
    for(ll k=n; k>=1; k--) {
        if(k<=target) {
            arr1.push_back(k);
            target -= k;
        }
        else arr2.push_back(k);
    }

    cout << "YES" << endl;
    cout << arr1.size() << endl;
    for(int x: arr1) cout << x << " ";
    cout << endl;
    cout << arr2.size() << endl;
    for(int x: arr2) cout << x << " ";
    cout << endl;
    
    return 0;
}
