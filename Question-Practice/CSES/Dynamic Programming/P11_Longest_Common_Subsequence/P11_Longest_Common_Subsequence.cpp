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
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int j=0; j<m; j++) cin >> b[j];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = dp[i-1][j-1] + (a[i-1]==b[j-1]);
            dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        }
    }

    cout << dp[n][m] << endl;

    vector<int> ans;
    int i=n, j=m;
    while(i>0 && j>0) {
        int curr = dp[i][j];
        if(curr==dp[i-1][j]) i--;
        else if(curr==dp[i][j-1]) j--;
        else if(curr==dp[i-1][j-1]) {
            i--;
            j--;
        }
        else {
            ans.push_back(a[i-1]);
            i--;
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    for(int x: ans) cout << x << " ";
    cout << endl;

    return 0;
}
