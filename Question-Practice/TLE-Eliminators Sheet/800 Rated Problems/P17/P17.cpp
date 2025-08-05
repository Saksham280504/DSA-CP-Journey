#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n,k,x;
    cin >> n >> k >> x;
    
    if(x!=1) {
        cout << "YES" << endl;
        cout << n << endl;
        for(int i=0; i<n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    else if(k==1) {
        cout << "NO" << endl;
        return;
    }
    else if(k==2 && n%2==1) {
        cout << "NO" << endl;
        return;
    }
    else {
        if(n%2==0) {
            cout << "YES" << endl;
            cout << n/2 << endl;
            for(int i=0; i<n/2; i++) {
                cout << 2 << " ";
            }
            cout << endl;
            return;
        }
        cout << "YES" << endl;
        int num = (n-3)/2;
        cout << num + 1 << endl;
        cout << 3 << " ";
        for(int i=0; i<num; i++) {
            cout << 2 << " ";
        }
        cout << endl;
        return;
    }
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
