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
    int n;
    cin >> n;
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        string a = to_string(i);
        for(char c: a) {
            int digit = c-'0';
            if(digit!=0) {
                dp[i] = min(dp[i],1+dp[i-digit]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
