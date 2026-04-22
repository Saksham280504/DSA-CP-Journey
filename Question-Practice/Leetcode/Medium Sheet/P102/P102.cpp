#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// We want (total-subarray)modp = 0
// So subarray mod p = total mod p = k
// Therefore, the problem will now deduce to -> find the smallest subarray such that subarray mod p = k
// prefix -> sum from 0 to i
// for any subarray sub from j+1 to i
// sub = prefix[i]-prefix[j]
// sub mod p = k -> (prefix[i]-prefix[j]) mod p = k -> prefix[j] mod p = (prefix[i]-k+p)mod p (because k might be > prefix[i], therefore we add p as it makes -k+p > 0 and also doesn't affect the remainder)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for(int x: nums) total += x;
        int k = total%p;
        if(k==0) return 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        long prefix = 0;
        int ans = nums.size();
        for(int i=0; i<nums.size(); i++) {
            prefix = (prefix+nums[i])%p;
            int target = (prefix-k+p)%p; // k might be bigger than prefix, therefore we added p as -k+p>=0 always.
            if(mpp.count(target)>0) {
                ans = min(ans,i-mpp[target]);
            }
            mpp[prefix] = i;
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
