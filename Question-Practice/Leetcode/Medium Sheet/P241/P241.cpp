#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        int currSub = 0;
        for(int i=0; i<n; i++) {
            if(currSub>nums[i]) return false; // element was subtracted more than what was needed
            // nums[i]>=currSub
            int needed = nums[i] - currSub;
            if(needed>0) {
                if(i+k>n) return false;
                currSub += needed;
                nums[i] = needed; 
            }
            else { // needed = 0, element got subtracted to 0 by the subarrays created by its predecessors
                nums[i] = 0;
            }
            if(i>=k-1) currSub -= nums[i-k+1];
        }
        return true;
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
