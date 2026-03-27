#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> temp = intervals[0];
    for(int i=1; i<n; i++) {
        if(temp[1]>=intervals[i][0]) temp[1] = max(temp[1],intervals[i][1]);
        else {
            ans.push_back(temp);
            temp = intervals[i];
        }
    }
    ans.push_back(temp);
    return ans; 
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
