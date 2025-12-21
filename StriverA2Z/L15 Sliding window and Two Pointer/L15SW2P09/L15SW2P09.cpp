#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    int numSubarrayWithSumAtMostK(vector<int>& nums, int k) {
        if(k<0) return 0;
        int l=0, r=0, sum=0, cnt=0;
        int n = nums.size();
        while(r<n) {
            sum += nums[r];
            while(sum>k) {
                sum -= nums[l];
                l++;
            }
            if(sum<=k) cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return numSubarrayWithSumAtMostK(nums,goal)-numSubarrayWithSumAtMostK(nums,goal-1);
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
