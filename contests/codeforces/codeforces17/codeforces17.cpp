#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve1(){
    int n;
    cin >> n;
    vector<int> arr(n);
    bool is67 = false;
    bool is1 = false;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i]==67) is67 = true;
        if(arr[i]==1) is1 = true;
    }

    if(is67 && is1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void solve2() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(int i=1; i<=n; i++) cin >> p[i];
    
    for(int i=1; i<=n; i+=2) {
        vector<int> indices;
        vector<int> values;
        int j=i;
        while(j<=n) {
            indices.push_back(j);
            values.push_back(p[j]);
            j*=2;
        }
        sort(indices.begin(), indices.end());
        sort(values.begin(), values.end());
        if(indices!=values) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

void solve3() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int cnt = 0;
    if(n==1) {
        cout << 0 << endl;
        return;
    }
    for(int i=0; i<n; i++) {
        if(a[i]==a[i+1] || a[i]+a[i+1]==7) cnt++;
    }
    cout << cnt << endl;
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
        solve3();
    }
    return 0;
}
