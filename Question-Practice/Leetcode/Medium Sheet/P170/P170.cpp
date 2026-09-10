#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    void dfs(string node, unordered_map<string,priority_queue<string,vector<string>,greater<string>>>& graph, vector<string>& route) {
        while(!graph[node].empty()) {
            string adj = graph[node].top();
            graph[node].pop();
            dfs(adj,graph,route);
        }
        route.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> graph;
        for(auto & edge: tickets) {
            string src = edge[0];
            string dest = edge[1];
            graph[src].push(dest);
        }
        vector<string> route;
        dfs("JFK",graph, route);
        reverse(route.begin(),route.end());
        return route;
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
