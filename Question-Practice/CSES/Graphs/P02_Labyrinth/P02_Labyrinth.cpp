#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

using pii = pair<int,int>;
vector<char> DIRECTIONS = {'R','D','L','U'};
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
    int n,m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<char>> prevDirection(n,vector<char>(m,'0'));
    pii start,end;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='A') start = {i,j};
            else if(grid[i][j]=='B') end = {i,j};
        }
    }

    queue<pii> q;
    q.push(start);
    vis[start.first][start.second] = true;
    bool found = false;
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for(int d=0; d<4; d++) {
            int newX = x + dirX[d];
            int newY = y + dirY[d];
            if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]!='#' && !vis[newX][newY]) {
                vis[newX][newY] = true;
                prevDirection[newX][newY] = DIRECTIONS[d];
                q.push({newX,newY});
                if(make_pair(newX,newY)==end) {
                    found = true;
                    break;
                }
            }
        }
    }
    if(!found) {
        cout << "NO" << endl;
        return 0;
    }


    string path;
    pii current = end;
    while(current!=start) {
        char dir = prevDirection[current.first][current.second];
        path.push_back(dir);
        int index = find(DIRECTIONS.begin(), DIRECTIONS.end(), dir) - DIRECTIONS.begin();
        current.first -= dirX[index];
        current.second -= dirY[index];
    }

    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;

    return 0;
}
