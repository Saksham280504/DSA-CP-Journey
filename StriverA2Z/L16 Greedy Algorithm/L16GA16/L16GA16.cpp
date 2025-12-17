#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    static bool comp(const vector<int>& item1, const vector<int>& item2) {
        return (item1[1]<item2[1]);
    }
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // This problem is the exact inverse of N meetings in one room, as there we were trying to put as many number of meetings (which have non over-lapping intervals) in one room. So if we subtract that number from the total number of meetings we get the count of those meets which were causing overlaps

        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp); // I want the intervals to be sorted by ending time (intervals[i-1][1]<intervals[i][1])
        int cnt = 1;
        int freeTime = intervals[0][1];

        for(int i=1; i<n; i++) {
            if(intervals[i][0]>=freeTime) {
                cnt++;
                freeTime = intervals[i][1];
            }
        }

        return n-cnt;

        // TC -> O(NlogN+N)
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
