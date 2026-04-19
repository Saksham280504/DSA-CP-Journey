#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// The core intuition of the problem is that one half of the array is always sorted, and the minimum lies in the unsorted half.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left<right) {
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right]) left = mid+1;
            else { // nums[mid]<=nums[right]
                right = mid;
            }
        }
        return nums[left];
    }

    // TC -> O(logN)
    // SC -> O(1)
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
