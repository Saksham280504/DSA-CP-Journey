#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool solve(int idx, vector<int>& nums, vector<int>& bucket, int target) {
        if(idx>=nums.size()) return true;
        for(int i=0; i<bucket.size(); i++) {
            if(i>0 && bucket[i]==bucket[i-1]) continue;
            if(bucket[i]+nums[idx]>target) continue;
            bucket[i] += nums[idx];
            if(solve(idx+1,nums,bucket,target)) return true;
            bucket[i] -= nums[idx];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        if(sum%k != 0) return 0;
        int target = sum/k;
        vector<int> bucket(k,0);
        return solve(0,nums,bucket,target);
    }

    // TC -> O(K*N) -> worst case but pruning makes it a lot better in practice
    // Pruning helps us in not going after similar procedures by taking a check of the current value with the previous value.
    // The bucket array stores the current sum of all the subsets. Every index of the bucket array shows the current sum of the k subsets.
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
