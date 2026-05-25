#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int max_val = 6000;
        vector<vector<bool>> vis(max_val+1,vector<bool>(2,false));
        // Forward -> 1
        // Backward -> 0

        for(int f: forbidden) {
            vis[f][0] = true;
            vis[f][1] = true;
        }

        queue<pair<int,int>> q; // {pos,type}
        q.push({0,0});
        q.push({0,1});
        vis[0][0] = true;
        vis[0][1] = true;
        
        int jumps = 0;

        while(!q.empty()) {
            int level_size = q.size();
            while(level_size--) {
                auto [curr, type] = q.front();
                q.pop();
                if(curr==x) return jumps;

                // Forward
                int up = curr + a;
                if(up<=max_val && !vis[up][1]) {
                    q.push({up,1});
                    vis[up][1] = true;
                }

                if(type==1) {
                    int down = curr - b;
                    if(down>=0 && !vis[down][0]) {
                        q.push({down,0});
                        vis[down][0] = true;
                    }
                }
            }
            jumps++;
        }

        return -1;
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
