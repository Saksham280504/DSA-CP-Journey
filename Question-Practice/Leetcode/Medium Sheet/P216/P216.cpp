#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Approach-1 -> TC->O(N),SC->O(N) -> Suffix min and prefix max approach
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix_min(n,1e9);
        suffix_min[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            suffix_min[i] = min(nums[i],suffix_min[i+1]);
        }
        int prefix_max = nums[0];
        for(int i=0; i<(n-1); i++) {
            prefix_max = max(prefix_max,nums[i]);
            if(prefix_max<=suffix_min[i+1]) return i+1;
        }
        return n;
    }
};

// Approach-2 : TC -> O(N), SC-> O(1)
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int left_max = nums[0]; // The maximum element of our till now accepted left array
        int maxi = nums[0]; // The maximum element of all the scanned so far elements
        int partitionIndex = 0;
        for(int i=1; i<n; i++) {
            maxi = max(maxi,nums[i]);
            if(nums[i]< left_max) {
                left_max = maxi;
                partitionIndex = i;
            }
        }
        return partitionIndex+1;
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
