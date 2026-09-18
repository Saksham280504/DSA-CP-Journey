#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    static bool comp(const vector<int>& interval1, const vector<int>& interval2) {
        return interval1[1]<interval2[1];
    }
    public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(), comp);
        int cnt = 1;
        int finishing_time = intervals[0][1];
        for(int i=1; i<n; i++) {
            if(intervals[i][0]>=finishing_time) {
                cnt++;
                finishing_time = intervals[i][1];
            }
        }
        return n-cnt;
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
