#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int mod = 1e9+7;
    int dfs(int u, int n, vector<vector<pair<int,int>>>& adjLS, vector<int>& dp, vector<int>& dist) {
        if(u==n) return 1;
        if(dp[u]!=-1) return dp[u];
        int ways = 0;
        for(auto &[v,w]: adjLS[u]) {
            if(dist[v] < dist[u]) {
                ways = (ways+dfs(v,n,adjLS,dp,dist))%mod;
            }
        }
        return dp[u] = ways;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adjLS(n+1);
        for(auto &edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adjLS[u].push_back({v,w});            
            adjLS[v].push_back({u,w});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        dist[n] = 0;
        pq.push({0,n});
        while(!pq.empty()) {
            auto [d,u] = pq.top();
            pq.pop();
            if(d>dist[u]) continue;
            for(auto &[v,w]: adjLS[u]) {
                if(dist[u]+w<dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }
        vector<int> dp(n+1,-1);
        return dfs(1,n,adjLS,dp,dist);
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
