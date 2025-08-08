#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // int cnt = 0;
    // for(int i=0; i<n-1; i++) {
    //     if((arr[i]%2==0 && arr[i+1]%2==0)||(arr[i]%2==1 && arr[i+1]%2==1)) {
    //         if(arr[i]%2==0) {
    //             arr[i] = 4;
    //         }
    //         else arr[i] = 1;
    //         arr.erase(arr.begin()+i+1);
    //         n = arr.size();
    //         i--;
    //         cnt++;
    //     }
    // }

    // cout << cnt  << endl;

    int ops = 0;
    int parity = arr[0]%2;
    int cnt = 0;
    for(int i=1; i<n; i++) {
        if(parity==arr[i]%2) cnt++;
        else {
            ops += cnt;
            cnt = 0;
            parity = arr[i]%2;
        }
    }
    ops += cnt;
    cout << ops << endl;
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
