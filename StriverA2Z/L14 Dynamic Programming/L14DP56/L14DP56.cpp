#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat;
    for(int i=0; i<n; i++) {
        vector<int> arr(m);
        for(int j=0; j<m; j++) cin >> arr[j];
        mat.push_back(arr);
    }

    // Here we follow the tabulation approach for better intuitive understanding. We are using a dp-array (nXm) and here dp[i][j] represents the total number of squares ending at (i,j) which (i,j) is the right-bottom end of the rectangle.


    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int j=0; j<m; j++) dp[0][j] = mat[0][j];
    for(int i=0; i<n; i++) dp[i][0] = mat[i][0];
    // The top-row and left-column elements will only form square of themselves only

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(mat[i][j]==0) dp[i][j]=0;
            else dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }

    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) sum += dp[i][j];
    }  

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cout <<  dp[i][j] << " ";
        cout << endl;
    }
    cout << endl;  
    
    cout << sum << endl;

    return 0;
}
