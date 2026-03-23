#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {

    // The core idea of the problem is: (prefixSum[j]-prefixSum[i])%k==0 => prefixSum[j]%k == prefixSum[i]%k
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> mpp;
        mpp[0] = -1;
        long long sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            int rem = sum%k;
            if(mpp.find(rem)!=mpp.end()) {
                if((i-mpp[rem])>1) return true;
            }
            else mpp[rem] = i;
        }

        return false;
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
