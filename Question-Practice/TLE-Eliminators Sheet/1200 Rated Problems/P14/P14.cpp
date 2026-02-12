#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> mat(n,vector<char>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> mat[i][j];
    }

    int minOperations = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int c0 = 0;
            int c1 = 0;
            if(mat[i][j]=='1') c1++;
            else c0++;
            if(mat[j][n-i-1]=='1') c1++;
            else c0++;
            if(mat[n-i-1][n-j-1]=='1') c1++;
            else c0++;
            if(mat[n-j-1][i]=='1') c1++;
            else c0++;

            if(c0==0 || c1==0) continue;
            if(c0<=c1) {
                minOperations += c0;
                mat[i][j] = '1';
                mat[j][n-i-1] = '1';
                mat[n-i-1][n-j-1] = '1';
                mat[n-j-1][i] = '1';
            }
            else {
                minOperations += c1;
                mat[i][j] = '0';
                mat[j][n-i-1] = '0';
                mat[n-i-1][n-j-1] = '0';
                mat[n-j-1][i] = '0';               
            }
        }
    }

    cout << minOperations << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
