#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int max_diff = nums[n-1]-nums[0];
        for(int i=0; i<(n-1); i++) {
            int maxi = max(nums[i]+k,nums[n-1]-k);
            int mini = min(nums[0]+k,nums[i+1]-k);
            max_diff = min(max_diff,maxi-mini);
        }
        return max_diff;
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
