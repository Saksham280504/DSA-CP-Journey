#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
ll mod = 1e9+7;

int main() {
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
    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }
    vector<vector<ll>> paths(n,vector<ll>(n,0));
    if(grid[0][0]=='*') {
        cout << 0 << endl;
        return 0;
    }
    paths[0][0] = 1;

    // For 0th row -> dp[0][j] = dp[0][j-1]
    for(int j=1; j<n; j++) {
        if(grid[0][j]=='.') paths[0][j] = paths[0][j-1];
    }

    // For 0th Column -> dp[i][0] = dp[i-1][0]
    for(int i=1; i<n; i++) {
        if(grid[i][0]=='.') paths[i][0] = paths[i-1][0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(grid[i][j]=='.') paths[i][j] = (paths[i][j-1]+paths[i-1][j])%mod;
        }
    }
    cout << paths[n-1][n-1] << endl;

    return 0;
}
