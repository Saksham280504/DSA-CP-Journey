#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    static bool comp(const vector<int>& bal1, const vector<int>& bal2) {
        return bal1[1]<bal2[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(),comp);
        int arrows = 1;
        int currArrow = points[0][1];
        for(int i=1; i<n; i++) {
            if(points[i][0]>currArrow) {
                arrows++;
                currArrow = points[i][1];
            }
        }
        return arrows;
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
