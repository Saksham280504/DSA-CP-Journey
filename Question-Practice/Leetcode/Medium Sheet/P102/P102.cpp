#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

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
