#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preRem(k,0);
        preRem[0] = 1;
        int currSum = 0;
        int ans = 0;
        // for a subarray nums[i...j] -> sum%k = (preSum[j] - preSum[i-1])%k==0 -> preSum[j]%k == preSum[i-1]%k == 0
        // since nums[i] can be -ve, therefore to store only +ve rems we will use rem = (sum%k + k)%k
        for(int i=0; i<n; i++) {
            currSum += nums[i];
            int rem = (currSum%k + k)%k;
            ans += preRem[rem];
            preRem[rem]++;
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
