#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// My solution -> SC -> O(N*M)
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j]) {
                    swap(mat[i][j],mat[n-1-j][i]);
                    swap(mat[n-1-j][i],mat[n-1-i][n-1-j]);
                    swap(mat[n-1-i][n-1-j],mat[j][n-1-i]);
                    vis[i][j] = true;
                    vis[j][n-1-i] = true;
                    vis[n-1-i][n-1-j] = true;
                    vis[n-1-j][i] = true;
                }
            }
        }
    }
};

// Optimal Solution -> SC -> O(1)
// Key idea- Transpose + reverse
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                swap(mat[i][j],mat[j][i]);
            }
        }
        
        for(int i=0; i<n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
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
