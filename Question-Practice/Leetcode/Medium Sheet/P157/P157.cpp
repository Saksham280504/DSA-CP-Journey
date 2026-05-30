#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// [0...i][i+1....j][j+1....n-1] -> (prefixSum[i]<= (prefixSum[j]-prefixSum[i]) <= (prefixSum[n-1]-prefixSum[j])) ---(i)
// i+1<=j<=n-2 ---(ii)
// for every i from [0...n-3] (inclusive), we need a j such that it follows both first and second condition
// Thus we create a first (for prefixSum[i]<= (prefixSum[j]-prefixSum[i])) that should give you the smallest value of j
// And last ((prefixSum[j]-prefixSum[i]) <= (prefixSum[n-1]-prefixSum[j])) that would give you a j greater than the largest value of j
// Thus the number of splits possible for that particular i is = (last-first) (if first<last)
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9+7;
        vector<long long> prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++) prefixSum[i] = nums[i] + prefixSum[i-1];

        long long TotalSum = prefixSum[n-1];
        long long ans = 0LL;

        for(int i=0; i<=n-3; i++) {
            long long leftSum = prefixSum[i];
            auto first = lower_bound(prefixSum.begin()+i+1, prefixSum.begin()+n-1, 2LL*leftSum);
            auto last = upper_bound(prefixSum.begin()+i+1,prefixSum.begin()+n-1, (TotalSum+leftSum)/2);

            ans = (ans + max(0LL, (long long)(last - first))) % mod;
        }

        return (int)ans;
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
