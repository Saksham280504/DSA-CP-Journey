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
    vector<int> arr1(n+1,0);
    vector<int> b;
    for(int i=n-1; i>=0; i--) {
        for(int j=n; j>=1; j--) {
            if(i==n-1) {
                b.push_back(n);
                arr1[n]++;
                break;
            }
            if(arr1[j]==1 || arr[i]+j>arr[i+1]+b[n-(i+2)]) {
                continue;
            }
            arr1[j]++;
            b.push_back(j);
            break;
        }
    }

    for(int i=n-1; i>=0; i--) {
        cout << b[i] << " ";
    }
    cout << endl;
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
