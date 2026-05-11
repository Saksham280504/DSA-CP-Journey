#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long mod = 1e9+7;
        vector<vector<long long>> mx(n,vector<long long>(m));
        vector<vector<long long>> mn(n,vector<long long>(m));
        mx[0][0] = mn[0][0] = grid[0][0];

        // For 0th row
        for(int j=1; j<m; j++) {
            mx[0][j] = mn[0][j] = mx[0][j-1]*grid[0][j];
        }

        // For 0th column
        for(int i=1; i<n; i++) {
            mx[i][0] = mn[i][0] = mx[i-1][0]*grid[i][0];
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                long long val = grid[i][j];
                long long a = mx[i-1][j]*val;
                long long b = mx[i][j-1]*val;
                long long c = mn[i-1][j]*val;
                long long d = mn[i][j-1]*val;
                mx[i][j] = max({a,b,c,d});
                mn[i][j] = min({a,b,c,d});
            }
        }
        long long ans = mx[n-1][m-1];
        if(ans<0) return -1;
        return ans%mod;

        // The key idea behind the problem is that negative*negative becomes positive. Therefore for every cell (i,j), we must track the maximum and minimum product reaching that cell. This is so because a very small negative product can later become the largest positive product.
        // Intuition:
        // Suppose we are at cell(i,j) and we come from top(i-1,j) or left(i,j-1).
        // If the current value is positive, then max stays max and min stays min.
        // If the current value is negative, then max may come from previous min and min also may come from previous max.

        // TC -> O(N*M)
        // SC -> O(2*N*M)
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
