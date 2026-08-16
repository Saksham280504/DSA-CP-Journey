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

    // Rather than going from every cell to 1, go from 1 to every cell. To find the minimum moves path, we use BFS.
    int n;
    cin >> n;
    vector<vector<int>> vis(n,vector<int>(n,-1));
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = 0;
    vector<pair<int,int>> delta = {{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2}};
    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--) {
            auto [x,y] = q.front();
            q.pop();
            for(auto del: delta) {
                int nx = x + del.first;
                int ny = y + del.second;
                if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==-1) {
                    q.push({nx,ny});
                    vis[nx][ny] = vis[x][y] + 1;
                }
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
