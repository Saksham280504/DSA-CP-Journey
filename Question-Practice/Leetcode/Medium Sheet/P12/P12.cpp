#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> row(n+1, vector<int>(m+1,0));
        vector<vector<int>> col(n+1, vector<int>(m+1,0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                row[i][j+1] = row[i][j] + grid[i][j]; // row[i][j] => grid[i][0] + ..... + grid[i][j-1]
                col[i+1][j] = col[i][j] + grid[i][j]; // col[i][j] => grid[0][j] + ..... + grid[i-1][j]
            }
        }

        for(int k = min(m,n); k>=1; k--) {
            for(int i=0; i+k<=n; i++) {
                for(int j=0; j+k<=m; j++) {
                    int target = row[i][j+k] - row[i][j];
                    bool ok = true;
                    for(int r=i; r<i+k; r++) {
                        if(row[r][j+k]-row[r][j]!=target) {
                            ok = false;
                            break;
                        }
                    }

                    if(!ok) continue;

                    for(int c=j; c<j+k; c++) {
                        if(col[i+k][c]-col[i][c]!= target) {
                            ok = false;
                            break;
                        }
                    }

                    if(!ok) continue;

                    int d1 = 0, d2 = 0;
                    for(int t=0; t<k; t++) {
                        d1 += grid[i+t][j+t];
                        d2 += grid[i+t][j+k-1-t];
                    }

                    if(d1!=target || d2!= target) ok = false;
                    if(ok) return k;
                }
            }
        }

        return 1;
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
