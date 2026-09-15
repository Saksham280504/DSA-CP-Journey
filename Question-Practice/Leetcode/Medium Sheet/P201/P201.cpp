#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> dp = {0,1,0,1}; // dp[0] -> is dummy
        // dp[r] -> minimum side jumps needed to reach rth lane of the ith point
        int INF = 1e9;
        for(int obs: obstacles) {
            if(obs>0) dp[obs] = INF;
            for(int r=1; r<=3; r++) {
                if(r!=obs) {
                    dp[r] = min({dp[r], dp[r==1 ? 2:(r==2 ? 1: 1)] + 1, dp[r==1 ? 3: (r==2 ? 3: 2)] + 1});
                }
            }
        }

        return min({dp[1],dp[2],dp[3]});
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
