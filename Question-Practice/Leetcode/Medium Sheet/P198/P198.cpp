#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    int n;
    int dfs(int idx, vector<int>& arr, vector<bool>& vis, vector<int>& dp) {
        if(arr[idx]==0) return true;
        if(dp[idx]!=-1) return dp[idx];
        vis[idx] = true;
        bool canVisit = false;
        int right = idx + arr[idx];
        int left = idx - arr[idx];
        if(right<n && !vis[right]) canVisit |= dfs(right,arr,vis,dp);
        if(left>=0 && !vis[left]) canVisit |= dfs(left,arr,vis,dp);
        vis[idx] = false;
        return dp[idx] = canVisit;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool> vis(n,false);
        vector<int> dp(n,-1);
        return dfs(start,arr,vis,dp);
    }
};

class Solution {
private:
    bool bfsPartition(int node, vector<vector<int>>& adjLS, vector<int>& teams) {
        queue<pair<int,int>> q; // {node,group}
        q.push({node,1});
        teams[node] = 1;
        while(!q.empty()) {
            auto [u,teamU] = q.front();
            q.pop();
            for(int v: adjLS[u]) {
                if(teams[v]==0) {
                    teams[v] = 0 - teamU;
                    q.push({v,teams[v]});
                }
                else if(teams[v]==teamU) return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjLS(n+1);
        for(auto &e: dislikes) {
            int a = e[0], b = e[1];
            adjLS[a].push_back(b);
            adjLS[b].push_back(a);
        }
        vector<int> color(n+1,0);
        for(int i=1; i<=n; i++) {
            if(!color[i]) {
                if(!bfsPartition(i,adjLS,color)) return false;
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
