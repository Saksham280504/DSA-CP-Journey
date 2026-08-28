#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adjLS[n+1];
        for(auto dis: dislikes) {
            adjLS[dis[0]].push_back(dis[1]);
            adjLS[dis[1]].push_back(dis[0]);
        }
        vector<int> color(n+1,0);
        for(int i=1; i<=n; i++) {
            if(color[i]!=0) continue;
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v: adjLS[u]) {
                    if(color[v]==color[u]) return false;
                    if(color[v]==0) {
                        color[v] = -color[u];
                        q.push(v);
                    }
                }
            }
        }
        return true;
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
