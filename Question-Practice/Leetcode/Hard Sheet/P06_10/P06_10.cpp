#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=2; j<=m; j++) {
            if(p[j-1]=='*') dp[0][j] = dp[0][j-2];
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(p[j-1]!='*') {
                    bool match = (p[j-1]==s[i-1] || p[j-1]=='.');
                    dp[i][j] = match && dp[i-1][j-1];
                }
                else {
                    // Considered zero time
                    bool zeroTime = dp[i][j-2];
                    // one or more Time
                    bool isMatched = (p[j-2]==s[i-1] || p[j-2]=='.');
                    bool oneOrMoreTime = isMatched && dp[i-1][j];
                    dp[i][j] = zeroTime || oneOrMoreTime;
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
