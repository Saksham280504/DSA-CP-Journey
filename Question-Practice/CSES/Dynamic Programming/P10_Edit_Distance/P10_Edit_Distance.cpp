#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    string a,b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<int> prev(m+1,1e9);
    for(int j=0; j<=m; j++) {
        prev[j] = j;
    }
    for(int i=1; i<=n; i++) {
        vector<int> curr(m+1,1e9);
        curr[0] = i;
        for(int j=1; j<=m; j++) {
            curr[j] = prev[j-1] + (a[i-1]!=b[j-1]); // replaced-> 1 / equal -> 0
            curr[j] = min(curr[j],min(curr[j-1],prev[j]) + 1); // either delete ith character from a (same as adding 1 character to b) or jth character from b (same as adding 1 character to a).
        }
        prev = curr;
    }
    cout << prev[m] << endl;

    return 0;
}
