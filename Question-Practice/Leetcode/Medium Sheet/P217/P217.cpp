#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_max = 0;
        int max_kadane = nums[0];
        int curr_min = 0;
        int min_kadane = nums[0];
        int total_sum = 0;
        for(int x: nums) {
            curr_max = max(x,curr_max+x);
            max_kadane = max(max_kadane,curr_max);
            curr_min = min(x,curr_min+x);
            min_kadane = min(min_kadane,curr_min);
            total_sum += x;
        }
        if(max_kadane<0) return max_kadane; // If array only have -ve elements, then max_kadane = *max_element(nums), thus return max_kadane
        return max(max_kadane,total_sum-min_kadane); // Otherwise return max(non-wrapped subarray, wrapped subarray)
    }
};

// There are two ways for us to get the maximum sum non-empty subarray: 1) No wrapping -> Simple maximum subarray sum in an Array using Kadane's Algorithm
// 2) Wrapped Subarray -> This array will look like -> [........x,x,x|x,x,x,x......] (double-length array) -> [x,x,x,[removed_middle_part],x,x,x] (single-length array) -> This means that wrapped_subarray_sum = total_sum - removed_middle_part_subarray_sum. To maximize the wrapped_subarray_sum we will have to find minimumm removed_middle_part_subarray_sum (reversed Kadane's algo)

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
