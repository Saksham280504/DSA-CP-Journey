#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>=k+maxPts) return 1.0;
        vector<double> dp(n+1,0.0); // dp[i] => probability of sum of points = i
        dp[0] = 1.0;
        double windowSum = 1.0;
        double ans = 0.0;
        for(int i=1; i<=n; i++) { // i-> total accumulated points until now
            dp[i] = windowSum/maxPts;
            if(i<k) { 
                windowSum += dp[i];
            }
            else { // i>=k
                ans += dp[i];
            }
            if(i>=maxPts) {
                windowSum -= dp[i-maxPts];
            }
        }
        return ans;
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
