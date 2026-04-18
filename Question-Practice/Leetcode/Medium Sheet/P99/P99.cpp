#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Core-intuition of the problem is that two negative numbers flip signs & zero resets everything.
// Therefore at every index we track two things:
// 1. currMax -> maximum product ending here
// 2. currMin -> minimum product ending here
// why currMin? because multiplying a negative number with the smallest (most negative) value can give the largest positive product.
// At each index there are three choices- either start a new subarray, extend previous max, extend previous min
// Negative numbers perform a swap effect -> currMax <=> currMin
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int num = nums[i];
            if(num<0) swap(currMax,currMin);
            currMax = max(num,currMax*num);
            currMin = min(num,currMin*num);
            res = max(res,currMax);
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
