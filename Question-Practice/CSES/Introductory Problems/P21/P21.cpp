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
    vector<string> grid(n);

    for(int i=0; i<n; i++) cin >> grid[i];

    vector<vector<char>> ans(n,vector<char>(m,'A'));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if((i+j)&1) ans[i][j] = (grid[i][j]=='C' ? 'D' : 'C');
            else ans[i][j] = (grid[i][j]=='A' ? 'B' : 'A');
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
