#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

using pii = pair<int,int>;
int n,m;
vector<string> grid;
vector<vector<int>> monster_time;
vector<vector<char>> parent;
vector<vector<bool>> vis;
vector<char> DIR = {'R','D', 'L', 'U'};
vector<int> dirX = {0,1,0,-1};
vector<int> dirY = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    cin >> n >> m;
    monster_time.assign(n,vector<int>(m,INT_MAX));
    grid.resize(n);
    parent.assign(n,vector<char>(m,'#'));
    vis.assign(n,vector<bool>(m,false));
    for(int i=0; i<n; i++) cin >> grid[i];

    // MultiSource BFS
    queue<pii> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='M') {
                q.push({i,j});
                monster_time[i][j] = 0;
            }
        }
    }
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for(int d=0; d<4; d++) {
            int nx = x + dirX[d];
            int ny = y + dirY[d];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#' && monster_time[x][y]+1<monster_time[nx][ny]) {
                monster_time[nx][ny] = monster_time[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    // Finding Shortest Safest Path
    vector<vector<int>> dist(n,vector<int>(m,0));
    bool escaped = false;
    pii end = {-1,-1}, start;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='A') {
                start = {i,j};
                q.push({i,j});
                vis[i][j] = true;
                break;
            }
        }
    }
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if(x==0 || y==0 || x==n-1 || y==m-1) {
            escaped = true;
            end = {x,y};
            break;
        }
        for(int d=0; d<4; d++) {
            int nx = x + dirX[d];
            int ny = y + dirY[d];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#' && dist[x][y]+1<monster_time[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = true;
                dist[nx][ny] = dist[x][y]+1;
                parent[nx][ny] = DIR[d];
                q.push({nx,ny});
            }
        }
    }

    if(!escaped) {
        cout << "NO" << endl;
        return 0;
    }
    string path;
    pii curr = end;
    while(curr!=start) {
        path.push_back(parent[curr.first][curr.second]);
        int idx = find(DIR.begin(), DIR.end(), parent[curr.first][curr.second]) - DIR.begin();
        curr.first -= dirX[idx];
        curr.second -= dirY[idx];
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;

    return 0;
}
