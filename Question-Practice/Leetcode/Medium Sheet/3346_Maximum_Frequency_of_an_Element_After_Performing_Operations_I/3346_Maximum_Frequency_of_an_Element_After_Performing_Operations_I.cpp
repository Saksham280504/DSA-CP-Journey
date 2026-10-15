#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int,int> count;
        for(int x: nums) count[x]++;
        int maxFreq = INT_MIN;
        // Case-1: Count[x] > 0
        for(auto &[x,freq] : count) {
            auto lb = lower_bound(nums.begin(),nums.end(),x-k); 
            auto rb = upper_bound(nums.begin(), nums.end(), x+k);
            int range = distance(lb,rb); // [x-k,x+k]
            int current = min(numOperations + count[x], range);
            maxFreq = max(maxFreq, current);
        }
        // Case-2: Count[x] == 0
        int left = 0;
        for(int right = 0; right<n; right++) {
            if(nums[right]-nums[left]>2*k) {
                left++;
            }
            int range = right-left+1;
            maxFreq = max(maxFreq,min(numOperations,range));
        }
        return maxFreq;
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
