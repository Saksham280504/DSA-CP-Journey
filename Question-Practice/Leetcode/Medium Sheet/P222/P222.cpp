#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// My Approach
class Solution {
    private:
        int numOfSubArraysWithSumAtMostK(int k, vector<int>& nums) {
            if(k<0) return 0;
            int n = nums.size();
            int l=0,r=0,sum=0,cnt=0;
            while(r<n) {
                sum += nums[r];
                while(sum>k) {
                    sum -= nums[l];
                    l++;
                }
                cnt += (r-l+1);
                r++;
            }
            return cnt;
        }
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return numOfSubArraysWithSumAtMostK(goal,nums)-numOfSubArraysWithSumAtMostK(goal-1,nums);
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


