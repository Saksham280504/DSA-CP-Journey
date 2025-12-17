#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int ind = 0;
        int n = intervals.size();
        
        // Left side of newInterval
        while(ind<n && intervals[ind][1] < newInterval[0]) {
            res.push_back(intervals[ind]);
            ind++;
        }

        // NewInterval
        while(ind<n && intervals[ind][0] < newInterval[1]) {
            newInterval[0] = min(intervals[ind][0],newInterval[0]);
            newInterval[1] = max(intervals[ind][1],newInterval[1]);
            ind++;
        }
        res.push_back(newInterval);

        while(ind<n) {
            res.push_back(intervals[ind]);
            ind++;
        }

        return res;

        // TC -> O(N)
        // SC -> O(2N)

        // Intervals array is already sorted!!
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
