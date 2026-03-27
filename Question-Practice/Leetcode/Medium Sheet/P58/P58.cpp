#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// The wrong thing about this approach is that only looks for the maximum yet found from left and gives answer according to that. You also need to give consideration to min_seen from right for accurate window creation.
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int cnt=0;
//         int maxi = INT_MIN;
//         int firstOccurance = -1;
//         int lastOccurance = -1;
//         for(int i=0; i<nums.size()-1; i++) {
//             maxi = max(maxi,nums[i]);
//             if(maxi>nums[i+1]) {
//                 if(cnt==0) firstOccurance = i;
//                 lastOccurance = i+1;
//                 cnt++;
//             }
//         }
//         if(firstOccurance==-1) return 0;
//         return lastOccurance-firstOccurance+1;
//     }
// };

// Correct Solution
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int max_Seen = INT_MIN;
        int right = -1;
        for(int i=0; i<nums.size(); i++) {
            max_Seen = max(max_Seen,nums[i]);
            if(nums[i]<max_Seen) right = i;
        }
        if(right==-1) return 0; // sorted

        int min_Seen = INT_MAX;
        int left = -1;
        for(int i=nums.size()-1; i>=0; i--) {
            min_Seen = min(min_Seen,nums[i]);
            if(nums[i]>min_Seen) left = i;
        }

        return (right-left+1);
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
