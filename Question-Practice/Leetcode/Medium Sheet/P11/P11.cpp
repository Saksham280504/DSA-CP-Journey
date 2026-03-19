#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                int x2 = min(topRight[i][0], topRight[j][0]);
                int y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                int y2 = min(topRight[i][1], topRight[j][1]);

                if(x2>x1 && y2>y1) {
                    long long width = x2 - x1;
                    long long height = y2 - y1;
                    long long side = min(width, height);
                    maxArea = max(maxArea, side*side);
                }
            }
        }

        return maxArea;
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
