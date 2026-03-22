#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(), days.end());
        int lastDay = days.back();
        vector<int> dp(lastDay+1,0);
        unordered_set<int> travel(days.begin(), days.end());

        for(int i=1; i<=lastDay; i++) {
            if(travel.find(i)==travel.end()) dp[i] = dp[i-1];
            else {
                int cost1 = dp[max(0,i-1)] + costs[0];
                int cost7 = dp[max(0,i-7)] + costs[1];
                int cost30 = dp[max(0,i-30)] + costs[2];
                dp[i] = min(cost1, min(cost7, cost30));
            }
        }

        return dp[lastDay];
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
