#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        // n<=m
        int low = 0;
        int high = n;
        int leftElements = (n+m+1)/2;
        while(low<=high) {
            int i = low + (high-low)/2; // total number of elements selected for left side from nums1
            int j = leftElements - i;
            int left1 = (i==0) ? INT_MIN:nums1[i-1];
            int right1 = (i==n) ? INT_MAX: nums1[i];
            int left2 = (j==0) ? INT_MIN:nums2[j-1];
            int right2 = (j==m) ? INT_MAX:nums2[j];
            if(left2<=right1 && left1<=right2) {
                int maxLeft = max(left1,left2);
                if((m+n)&1) return maxLeft;
                else {
                    int minRight = min(right1,right2);
                    return ((double)maxLeft+(double)minRight)/2.0;
                }
            }
            else if(left1>right2) { // i is too much to the right
                high = i-1;
            }
            else { // left2>right1 -> j is too much to the right -> i is too much to the left
                low = i+1;
            }
        }
        return 0.0;
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
