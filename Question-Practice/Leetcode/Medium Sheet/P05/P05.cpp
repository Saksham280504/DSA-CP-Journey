#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preSum(n,0);
        preSum[0] = nums[0];
        for(int i=1; i<n; i++) preSum[i] = preSum[i-1] + nums[i];
        vector<bool> inc(n,false);
        inc[0] = true;
        for(int i=1; i<n; i++) inc[i] = inc[i-1] && (nums[i]>nums[i-1]);
        vector<bool> dec(n,false);
        dec[n-1] = true;
        for(int i=n-2; i>=0; i--) dec[i] = dec[i+1] && (nums[i]>nums[i+1]);
        long long mini = LLONG_MAX;
        for(int i=0; i<n-1; i++) {
            if(inc[i] && dec[i+1]) {
                long long leftSum = preSum[i];
                long long RightSum = preSum[n-1] - preSum[i];
                mini = min(mini,abs(leftSum-RightSum));
            }
        }

        return mini == LLONG_MAX ? -1 : mini;
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
