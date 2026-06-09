#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

string s;
bool vis[9][9];
int ans = 0;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

void dfs(int r, int c, int idx) {
    if(r==7 && c==1) {
        if(idx==48) ans++;
        return;
    }
    if(idx==48) return;


    // Pruning: path splits grid into two parts
    if(vis[r-1][c] && vis[r+1][c] && !vis[r][c-1] && !vis[r][c+1]) return;
    if(vis[r][c-1] && vis[r][c+1] && !vis[r-1][c] && !vis[r+1][c]) return;

    vis[r][c] = true;

    char ch = s[idx];

    if(ch=='?') {
        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!vis[nr][nc]) {
                dfs(nr,nc,idx+1);
            }
        }
    }
    else {
        int k;
        if(ch=='U') k = 0;
        else if(ch=='R') k = 1;
        else if(ch=='D') k = 2;
        else k = 3;
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(!vis[nr][nc]) dfs(nr,nc,idx+1);
    }
    vis[r][c] = false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Write your code here
    cin >> s;
    for(int i=0; i<9; i++) {
        vis[i][0] = vis[i][8] = true;
        vis[0][i] = vis[8][i] = true;
    }
    dfs(1,1,0);

    cout << ans << endl;

    return 0;
}
