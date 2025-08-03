#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void solve() {
    vector<vector<char>> target;
    for(int i=0; i<10; i++) {
        vector<char> line(10);
        for(int j=0; j<10; j++) {
            cin >> line[j];
        }
        target.push_back(line);
    }

    int score = 0;
    int scoreLine = 0;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            int row = min(i+1,10-i);
            int col = min(j+1,10-j);
            scoreLine = min(row,col);
            if(target[i][j]=='X') score += scoreLine;
        }
    }

    cout << score << endl;
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
    while(t--) {
        solve();
    }
    return 0;
}
