#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve1() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        maxi = max(maxi,arr[i]);
        mini = min(mini,arr[i]);
    }
    cout << (maxi-mini+1) << endl;
}

void solve2() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(n==k) {
        cout << "NO" << endl;
        return;
    }
    for(int i=0; i<=(n-1-k); i++) {
        if(s[i]=='1') {
            s[i] = 0;
            if(s[i+k]=='1') s[i+k] = '0';
            else s[i+k] = '1';
        }
    }
    for(int i=(n-k); i<n; i++) {
        if(s[i]=='1') {
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
    while(t--) solve2();

    return 0;
}
