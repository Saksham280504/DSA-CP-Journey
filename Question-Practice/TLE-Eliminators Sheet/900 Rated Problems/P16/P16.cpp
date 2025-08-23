#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    string s,t;
    cin >> s >> t;
    map<char,int> mpp;
    int n = s.size();
    int m = t.size();

    for(int i=0; i<m; i++) {
        mpp[t[i]]++;
    }
    for(int i=n-1; i>=0; i--) {
        if(mpp.find(s[i]) != mpp.end()) {
            if(mpp[s[i]]==0) s[i] ='.';
            else mpp[s[i]]--;
        }
        else s[i]='.';
    }

    string newString = "";
    for(int i=0; i<n; i++) {
        if(s[i]!='.') newString += s[i];
    }
    if(newString==t) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    
    int n;
    cin >> n;
    while(n--) {
        solve();
    }

    return 0;
}