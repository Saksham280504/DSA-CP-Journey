#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

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

void solve3() {
    ll a,b,x;
    cin >> a >> b >> x;
    ll ops = 0;
    if(a==b) {
        cout << ops << endl;
        return;
    }
    if(x>=max(a,b)) {
        ops = abs(a-b);
        a/=x;
        b/=x;
        ops = min(ops,(2+abs(a-b)));
        cout << ops << endl;
        return;
    }
    ll maxi = max(a,b);
    ll mini = min(a,b);
    while((maxi/x) >= mini) {
        ops++;
        maxi /= x;
    }
    ll divide = ops;
    ops += (maxi-mini);
    maxi /= x;
    ops = min(ops,divide+1+mini-maxi);
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
    while(t--) solve3();

    return 0;
}
