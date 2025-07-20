#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void minOperations(vector<vector<ll>>& arr, ll n) {

}

void isGridPossible(int n, int m) {
    if(n==1 || m==1||(n==2 && m==2)) {
        cout << "NO" << endl;
        return;
    }
    else cout << "YES" << endl;
}
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    ll t;
    cin >> t;

    for(ll i=1; i<=t; i++) {
        ll n;
        cin >> n;
        vector<vector<ll>> completeArr(n);
        for(ll i=0; i<n; i++) {
            vector<ll> arr(4);
            for(int j=0; j<4; j++) {
                cin >> arr[j];
            }
            completeArr[i] = arr;
        }
        
        minOperations(completeArr,n);
    }

    return 0;
}
