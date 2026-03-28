#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]) { // whenever we are unable to pick a sector we shrink the search space
                low++;
                high--;
            }
            // left is sorted
            else if(nums[low]<=nums[mid]) {
                if(nums[low]<=target && target < nums[mid]) {
                    high = mid-1;
                } 
                else low = mid+1;
            }
            else { // right is sorted
                if(nums[mid] < target && target<=nums[high]) {
                    low = mid+1;
                }
                else high = mid-1;
            }
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
