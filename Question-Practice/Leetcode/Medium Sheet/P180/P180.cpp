#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        int maxLen = 1;
        int maxIdx = 0;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]%nums[j]==0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
            if(dp[i]>maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        vector<int> result;
        int curr = maxIdx;
        while(curr!=-1) {
            result.push_back(nums[curr]);
            curr = parent[curr];
        }
        return result;
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
