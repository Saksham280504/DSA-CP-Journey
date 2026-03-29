#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9+7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Computing powers of 2
        vector<int> power(n);
        power[0] = 1;
        for(int i=1; i<n; i++) {
            power[i] = (power[i-1]*2)%mod;
        }

        int ans=0, l=0, r=n-1;
        while(l<=r) {
            if(nums[l]+nums[r]<=target) {
                ans = (ans+power[r-l])%mod; // Here we see that all the elements in the range [l+1,...,r], we have a choice to either take them or not.
                // Very important thing to notice here is that I am always keeping my minimum(nums[l]) fixed and a part of my every subsequence, then only am I checking to which extent is the subsequence extendable.
                // So whenver this (nums[l]+nums[r]<=target) is true, I always look for the number of subsequence starting from nums[l], and then I do l++, which ensures that everytime I am getting new minimums after I have added all the valid subsequences with the previous minimum into my answer.

                // Input: nums = [3,3,6,8], target = 10
                // Output: 6
                // Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
                // [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
                // This shows that I don't need to find unique subsequences, I need to find them all.
                l++;
            }
            else {
                r--;
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
