#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> st;
    vector<int> prefix(n);
    for(int i=0; i<n; i++) {
        st.insert(s[i]);
        prefix[i] = st.size();
    }
    st.clear();
    vector<int> suffix(n);
    for(int i=n-1; i>=0; i--) {
        st.insert(s[i]);
        suffix[i] = st.size();
    }
    int maxLen = INT_MIN;
    for(int i=0; i<n-1; i++) {
        maxLen = max(maxLen, prefix[i]+suffix[i+1]);
    }
    maxLen = max(maxLen, prefix[n-1]);
    
    cout << maxLen << endl;

    // The greedy approach here is that we are trying to maximize f(a) + f(b)-> prefix[i] + suffix[i+1]
    // TC -> O(3N)
    // SC -> O(3N)
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
