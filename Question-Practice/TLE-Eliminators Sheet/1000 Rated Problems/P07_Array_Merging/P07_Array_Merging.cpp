#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n; 
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    vector<int> b(n);
    for(auto &x: b) cin >> x;

    vector<int> max_subarray_a(2*n+1,0); // These arrays will store the maximum size subarray for each element of a and b, the important concept to see here is that a[i], b[i] can at max go upto 2*n (given in the question) 
    vector<int> max_subarray_b(2*n+1,0);

    int cnt = 1;

    for(int i=1; i<n; i++) {
        if(a[i]==a[i-1]) cnt++;
        else {
            max_subarray_a[a[i-1]] = max(cnt, max_subarray_a[a[i-1]]);
            cnt = 1;
        }
    }

    max_subarray_a[a[n-1]] = max(cnt, max_subarray_a[a[n-1]]);
    cnt = 1;

    for(int i=1; i<n; i++) {
        if(b[i]==b[i-1]) cnt++;
        else {
            max_subarray_b[b[i-1]] = max(cnt, max_subarray_b[b[i-1]]);
            cnt = 1;
        }
    }

    max_subarray_b[b[n-1]] = max(cnt, max_subarray_b[b[n-1]]);
    cnt = 1;

    int maxLen = INT_MIN;
    for(int i=0; i<=2*n; i++) {
        maxLen = max(maxLen, max_subarray_a[i] + max_subarray_b[i]);
    }

    cout << maxLen << endl;
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
    while(t--) solve();

    return 0;
}
