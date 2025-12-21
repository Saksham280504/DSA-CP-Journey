#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Count the number of subarrays with number of odd elements >= k

class Solution {
    private: 
    int numOfSubarraysWithAtMostKOdd(vector<int>& nums, int k) {
        if(k<0) return 0;
        int l= 0, r=0, cnt=0, num=0;
        int n = nums.size();
        while(r<n) {
            if(nums[r]%2==1) cnt++;
            while(cnt>k) {
                cnt -= (nums[l]%2==1);
                l++;
            }
            if(cnt<=k) num += (r-l+1);
            r++;
        }
        return num;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) { // This is the same question as before, all we have to is to take all even numbers as 0 and all odd numbers as 1
        return numOfSubarraysWithAtMostKOdd(nums,k) - numOfSubarraysWithAtMostKOdd(nums,k-1);
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
