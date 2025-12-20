#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0,maxLen=0,zeros=0;
        while(r<n) {
            if(nums[r]==0) zeros++;
            if(zeros>k) {
                if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k) maxLen = max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }

    // TC -> O(N)
    // SC -> O(1)
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
