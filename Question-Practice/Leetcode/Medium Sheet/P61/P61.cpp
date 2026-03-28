#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int m = costs.size();
        vector<int> diff1, diff2;
        int cost=0;
        for(int i=0; i<m; i++) {
            if(costs[i][0]<=costs[i][1]) {
                diff1.push_back(costs[i][1]-costs[i][0]);
                cost += costs[i][0];
            }
            else { // costs[i][1]<costs[i][0]
                diff2.push_back(costs[i][0]-costs[i][1]);
                cost += costs[i][1];
            }
        }
        int cnt1 = diff1.size(), cnt2 = diff2.size();
        if(cnt1==cnt2) return cost;
        else if(cnt2>cnt1) { //costs[i][1]<costs[i][0]
            int req = (cnt2-cnt1)/2;
            sort(diff2.begin(), diff2.end());
            for(int i=0; i<req; i++) {
                cost += diff2[i];
            }
        }
        else { // costs[i][0]<=costs[i][1]
            int req = (cnt1-cnt2)/2;
            sort(diff1.begin(),diff1.end());
            for(int i=0; i<req; i++) {
                cost += diff1[i];
            }
        }

        return cost;
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
