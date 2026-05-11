#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int val = min(rowSum[i], colSum[j]);
                mat[i][j] = val;
                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }
        return mat;

        // TC -> O(N*M)
        // The key idea of the problem is that on the way, I have to fulfill the requirements of the ith Row and jth Column (mat[i][j]) immediately. This is so because at cell (i,j), row i still needs rowSum[i] and col j still needs colSum[j]. Therefore, the maximum value of the cell(i,j) = min(rowSum[i],colSum[j]). Once you place that value at mat[i][j], you remove that value from both the sums and then try to adjust the remainders. This is the core principle of the greedy approach we use here.
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
