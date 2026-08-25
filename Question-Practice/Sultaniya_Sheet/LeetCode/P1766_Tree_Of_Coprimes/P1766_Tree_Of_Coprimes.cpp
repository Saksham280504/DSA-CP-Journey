#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int is_Coprime[51][51];
    pair<int,int> ancestors[51]; // ancestor[val] = {node_id,depth} for the nearest ancestor found for val

    void dfs(int u, int p, int depth, vector<int> adjLS[], vector<int>& nums, vector<int>& ans) {
        int val_u = nums[u];
        int max_depth = -1;
        int closest_ancestor = -1;

        for(int v=1; v<51; v++) {
            if(is_Coprime[val_u][v]) {
                auto [anc_id, anc_depth] = ancestors[v];
                if(max_depth<anc_depth) {
                    max_depth = anc_depth;
                    closest_ancestor = anc_id;
                }
            }
        }

        ans[u] = closest_ancestor;

        auto prev_state = ancestors[val_u];
        ancestors[val_u] = {u,depth};
        for(int v: adjLS[u]) {
            if(v==p) continue;
            dfs(v,u,depth+1,adjLS,nums,ans);
        }
        ancestors[val_u] = prev_state;
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        // Pre-compute if values are coprime or not
        for(int i=1; i<51; i++) {
            for(int j=1; j<51; j++) {
                is_Coprime[i][j] = (__gcd(i,j)==1);
            }
        }
        int n = nums.size();

        vector<int> adjLS[n];
        for(auto &e: edges) {
            adjLS[e[0]].push_back(e[1]);
            adjLS[e[1]].push_back(e[0]);
        }
        
        for(int i=1; i<51; i++) {
            ancestors[i] = {-1,-1};
        }

        vector<int> ans(n,-1);
        dfs(0,-1,0,adjLS,nums,ans);
        return ans;
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
