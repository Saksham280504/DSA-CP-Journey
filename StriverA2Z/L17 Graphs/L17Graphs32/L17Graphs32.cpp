#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int minEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    // {diff,{r,c}}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dist(n,vector<int>(m,1e9)); // dist array holds the minimum effort needed to reach from (0,0) to (i,j)

    dist[0][0] = 0;
    pq.push({0,{0,0}});
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;
        if(row==n-1 && col==m-1) return diff; // The importance of the priority queue is that it follows minimum_heap, which means that whenever we use pq.top() it will give us {diff,{i,j}}. For this (i,j) cell, we will see that diff is actually the minimum effort needed to reach from (0,0) to (i,j). There might be some other paths still possible but all of those will give an effort greater than this. Thus for every cell which reaches to the top of the priority queue, the min_heap makes it confirmed for us that it has the best possible (minimum) answer.

        for(int i=0; i<4; i++) {
            int nrow = row +delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m) {
                int newEffort = max(diff,abs(heights[row][col]-heights[nrow][ncol]));
                if(newEffort<dist[nrow][ncol]) {
                    dist[nrow][ncol] = newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
            }
        }

    }

    return 0; // unreachable (will not happen)

    // TC -> O(ElogV)
    // Where E-> Number of edges (N*M*4)
    // V -> Number of Nodes (N*M)
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

    return 0;
}
