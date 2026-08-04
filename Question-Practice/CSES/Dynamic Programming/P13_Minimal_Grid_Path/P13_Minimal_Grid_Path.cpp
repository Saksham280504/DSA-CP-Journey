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
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }

    int i=0, j=0;
    while(i<(n-1) && j<(n-1)) {
        if(grid[i][j+1]<=grid[i+1][j]) {

        }
    }

    return 0;
}
