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
    
    vector<int> st;
    for(int i=0; i<n; i++) {
        if(arr[i]==2) st.push_back(i);
    }
    int m = st.size();
    if(m==0) {
        cout << 1 << endl;
        return;
    }
    if(m%2==1) {
        cout << -1 << endl;
        return;
    }
    int l = (m/2)-1;
    cout << st[l]+1 << endl;
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
