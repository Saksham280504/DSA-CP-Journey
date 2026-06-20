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
    int n,k;
    cin >> n >> k;
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<ll> arr(n);

    for(int i=0; i<n; i++) {
        if(i==0) arr[i] = x;
        else arr[i] = ((a*(arr[i-1]))+b)%c;
    }

    ll w_xor=0, net_xor = 0;
    int i=0; 
    for(int j=0; j<n; j++) {
        // Insertion
        w_xor ^= arr[j];

        // Deletion
        if((j-i+1)<k) continue;
        else { 
            net_xor ^= w_xor;
            w_xor ^= arr[i];
            i++;
        }
    }
    cout << net_xor << endl;

    return 0;
}
