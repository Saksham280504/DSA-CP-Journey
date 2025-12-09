#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int timer = 1;
void dfsCheck(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<int>& mark, vector<int> adjLS[]) {
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;
    int child = 0;
    for(auto adjNode: adjLS[node]) {
        if(adjNode==parent) continue;
        else if(!vis[adjNode]) {
            dfsCheck(adjNode,node,vis,tin,low,mark,adjLS);
            low[node] = min(low[node],low[adjNode]);
            if(low[adjNode]>=tin[node] && parent!=-1) {
                mark[node] = 1;
            }
            child++; 
            // Why this works is because we know that in dfs traversal, all children are traversed one by one, so if after the traversal of one child, we see that there exists a child which is not visited, this would have happened because that child have no whatsoever connection with the past child. Therefore, we only want independent child count of a parent and if a parent has more than one independent children, then that parent is an articulation point. I have also added an image with some other explanation too.
        }
        else {
            low[node] = min(low[node],tin[adjNode]);
        }
    }
    if(child>1 && parent==-1) { // Only for the parent node of a component
        mark[node] = 1; 
    }
}
vector<int> articulationPoints(int n, vector<int> adjLS[]) {
    vector<int> vis(n,0), tin(n), low(n), mark(n,0);
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfsCheck(0,-1,vis,tin,low,mark,adjLS);
        }
    }
    vector<int> ans;
    for(int i=0; i<n; i++) {
        if(mark[i]==1) ans.push_back(i);
    }
    if(ans.size()==0) return {-1};
    return ans;

    // TC -> O(V+2E)
    // SC -> O(4N)
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // Articulation point:

    // Any point/node on graph on whose removal the graph gets broken down into multiple components, is known as articulation point.

    // The concept we used in bridges will also be used here, but with some tweeks.

    // Tweek-1:- In low[] vector will now consist of lowest time of insertion of adjacent nodes of a node which are neither parent nor visited. For non-parent visited nodes, we will take low[node] = tin[adjNode]. This is so because to check for an articulation point, we don't want the adjacent nodes to find a way to reach back to that node, instead they should be able to reach to a node before it. If they are able to reach the node before it, then that node is not an articulation point, otherwise it is.
    // Tweelk-2:- We will never apply the algo for the starting point (where parent==-1), whereas we will check

    return 0;
}
