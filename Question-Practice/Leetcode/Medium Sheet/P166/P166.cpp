#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==1) matrix[i][j] = matrix[i-1][j] + 1;
            }
        }
        for(int i=0; i<n; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for(int j=0;j<m; j++) {
                maxArea = max(maxArea,(j+1)*(matrix[i][j]));
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
