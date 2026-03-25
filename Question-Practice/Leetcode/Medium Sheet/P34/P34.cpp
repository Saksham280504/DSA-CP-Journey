#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {

    // Core principle is that one half of the array is always sorted. You just need to check which half is sorted and then will your target lie in that sorted section and then apply binary search accordingly.
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left<=right) {
            int mid =left + (right-left)/2;
            if(nums[mid]==target) return mid;
            if(nums[left]<=nums[mid]) { // left half is sorted
                if(nums[left]<=target && target<nums[mid]) right = mid-1; // target lies in the sorted half
                else left = mid+1; // target doesn't lie in the sorted half
            }
            else { // right half is sorted
                if(nums[mid]<target && target<=nums[right]) left = mid+1; // target lies in the sorted half
                else right = mid-1; // target doesn't lie in the sorted half
            }
        }
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
