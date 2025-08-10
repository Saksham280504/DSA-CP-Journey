#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k = 0;
    int cnt = 0;
    for(int j=0; j<n; j++) {
        if(arr[j]==j+1) continue;
        for(int i=j+1; i<n; i++) {
            if(arr[i]==j+1) {
                if(cnt== 0) {
                    k = i-j;
                    cnt = 1;
                    swap(arr[i],arr[j]);
                } 
                else {
                    k = __gcd(i-j,k);
                    swap(arr[i],arr[j]);
                }
            }
        }
    }

    cout << k << endl;
    
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
