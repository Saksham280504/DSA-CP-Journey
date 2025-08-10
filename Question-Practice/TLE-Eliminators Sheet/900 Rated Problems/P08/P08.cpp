#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxi = INT_MIN;
    for(int i=0; i<n; i++) {
        int flag = 1;
        for(int j=i+1; j<n; j++) {
            if(s[j]!=s[i]) {
                maxi = max(j-i,maxi);
                flag = 0;
                break;
            }
        }
        if(flag) {
            maxi = max(n-i,maxi);
            break;
        }
    }
    cout << maxi+1<< endl;
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
