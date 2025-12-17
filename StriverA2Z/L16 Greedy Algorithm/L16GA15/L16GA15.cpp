#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    
    // Step 1. Always sort the given array, this makes sure that the overlapping intervals are contiguous
    sort(intervals.begin(),intervals.end());

    // Step 2.
    // Apply iteration
    vector<vector<int>> ans;
    vector<int> temp = intervals[0];
    for(int i=1; i<n; i++) {
        if(temp[1]>=intervals[i][0]) {
            temp[1] = max(intervals[i][1],temp[1]);
        }
        else {
            ans.push_back(temp);
            temp = intervals[i];
        }
    }

    ans.push_back(temp);
    return ans;

    // // TC -> O(nlogn + n)
    // // SC -> O(n)
    // }
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
