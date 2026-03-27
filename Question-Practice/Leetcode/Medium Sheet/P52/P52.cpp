#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        int n = intervals.size();

        // Left-side of the new Interval
        while(i<n && intervals[i][1]<newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        // New Interval
        while(i<n && intervals[i][0]<=newInterval[1]) {
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        // Right-side of the new Interval
        while(i<n) { // intervals[i][0] > newInterval[1]
            res.push_back(intervals[i]);
            i++;
        }

        return res;

        // TC -> O(N)
        // SC -> O(2N)
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
