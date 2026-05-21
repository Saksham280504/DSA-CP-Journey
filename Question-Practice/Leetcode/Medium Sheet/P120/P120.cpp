#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);

        for(auto &e: redEdges) { // This will store all the red-edged neighbours of a node
            red[e[0]].push_back(e[1]);
        }

        for(auto &e: blueEdges) { // This will store all the blue-edged neighbours of a node
            blue[e[0]].push_back(e[1]);
        }

        vector<int> ans(n,-1); // ans[x] -> minimum distance of node x from node 0 on a path having alternate colors. 
        int dist = 0; // dist shows the current distance from node 0.
        queue<pair<int,int>> q; // {node,lastColor}
        vector<vector<bool>> vis(n,vector<bool>(2,false)); // vis[node][lastColor]
        // 0-> red
        // 1-> blue
        
        q.push({0,0});
        q.push({0,1});

        vis[0][0] = true;
        vis[0][1] = true;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [node, color] = q.front();
                q.pop();
                if(ans[node]==-1) {
                    ans[node] = dist;
                }

                if(color==0) { // LastColor = red
                    for(auto nei: blue[node]) {
                        if(!vis[nei][1]) {
                            q.push({nei,1});
                            vis[nei][1] = true;
                        }
                    }
                }

                else { // LastColor = blue
                    for(auto nei: red[node]) {
                        if(!vis[nei][0]) {
                            q.push({nei,0});
                            vis[nei][0] = true;
                        }
                    }
                }
            }
            dist++;
        }

        return ans;

        // This is a classic BFS-state tracking problem. BFS because all the edges of the directed graph are of same weight and we want the closest path. State tracking because we want a path with alternating colors only and for that we need to keep a track of the LastColor of the node.
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
