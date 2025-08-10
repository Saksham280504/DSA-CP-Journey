#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr(n+1);
    arr[0] = 100;
    for(int i=0; i<n; i++) {
        if(s[i]=='<') arr[i+1] = arr[i]+1;
        else arr[i+1] = arr[i]-1;
    }

    set<int> st;
    for(int i=0; i<n+1; i++) {
        st.insert(arr[i]);
    }

    cout << st.size() << endl;
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
