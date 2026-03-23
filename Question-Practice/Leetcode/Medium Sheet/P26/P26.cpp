#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> maxD, minD;
        int l = 0, ans = 0;
        for(int r=0; r<n; r++) {
            while(!maxD.empty() && nums[r]>maxD.back()) {
                maxD.pop_back();
            }
            maxD.push_back(nums[r]);
            while(!minD.empty() && nums[r]<minD.back()) {
                minD.pop_back();
            }
            minD.push_back(nums[r]);

            while(maxD.front()-minD.front() > limit) {
                if(nums[l]==maxD.front()) maxD.pop_front();
                if(nums[l]==minD.front()) minD.pop_front();
                l++;
            }

            ans = max(ans, r-l+1);
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
