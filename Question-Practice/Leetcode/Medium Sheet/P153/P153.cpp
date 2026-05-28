#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0]; // Base-Case
        deque<int> dq;
        dq.push_back(0);

        for(int i=1; i<n; i++) {
            while(!dq.empty() && dq.front()<i-k) dq.pop_front();

            dp[i] = nums[i] + dp[dq.front()];

            while(!dq.empty() && dp[dq.back()]<=dp[i]) dq.pop_back();

            dq.push_back(i);
        }

        return dp[n-1];
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
