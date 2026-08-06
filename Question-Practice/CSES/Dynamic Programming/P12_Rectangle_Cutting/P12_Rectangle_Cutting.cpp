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
    int a,b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));

    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            if(i==j) {
                dp[i][j] = 0;
                continue;
            }
            for(int x=1; x<i; x++) {
                dp[i][j] = min(dp[i][j], 1+dp[i-x][j]+dp[x][j]);
            }
            for(int y=1; y<j; y++) {
                dp[i][j] = min(dp[i][j], 1+dp[i][j-y]+dp[i][y]);
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}
