#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int gcd(int x, int y) {
    int h = 1;
    int hcf = 1;
    while(h<=x && h<=y) {
        if(x%h==0 && y%h==0) hcf = max(hcf,h);
        h++;
    }
    return hcf;
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int hcf = arr[0];
    for(int j=1; j<n; j++) {
        hcf = gcd(hcf,arr[j]);
        if(hcf > j+1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
