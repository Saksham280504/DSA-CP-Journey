#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        for(int i=1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        int res = nums[firstLen+secondLen-1];
        int maxFirst = nums[firstLen-1];
        int maxSecond = nums[secondLen-1];
        for(int i=firstLen+secondLen; i<n; i++) {
            maxFirst = max(maxFirst,nums[i-secondLen]-nums[i-secondLen-firstLen]);
            maxSecond = max(maxSecond, nums[i-firstLen]-nums[i-firstLen-secondLen]);
            int currFirst = maxFirst + nums[i]-nums[i-secondLen];
            int currSecond = maxSecond + nums[i]-nums[i-firstLen];
            res = max({res,currFirst,currSecond});
        }
        return res;
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
