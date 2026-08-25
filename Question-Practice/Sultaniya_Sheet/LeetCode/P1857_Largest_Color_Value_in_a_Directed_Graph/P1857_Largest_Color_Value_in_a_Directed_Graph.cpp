#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adjLS[n];
        vector<int> indeg(n,0);
        for(auto &e: edges) {
            int u = e[0];
            int v = e[1];
            adjLS[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indeg[i]==0) q.push(i);
        }
        
        vector<vector<int>> dp(n,vector<int>(26,0));
        // dp[u][c] -> maximum frequency of color c in a path ending at node u
        int visited_count = 0;
        int max_color_value = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            visited_count++;
            dp[u][colors[u]-'a']++;
            max_color_value = max(max_color_value,dp[u][colors[u]-'a']);
            for(int v: adjLS[u]) {
                for(int c=0; c<26; c++) dp[v][c] = max(dp[v][c],dp[u][c]);
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        return (visited_count==n? max_color_value: -1);
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
