#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int swimInWater(vector<vector<int>>& grid) {
    // I couldn't make this question on my own and my first mistake was to think that this must be a disjoint set question. That is not the case!!
    // We know that whenever we are asked the minimum possible path, we always and always apply dijkstra.
    // The question is simple!! You are given a grid with elevations of each cell of the grid. Rain is just a distraction, overall the problem wants to say that any particular grid cell becomes reachable when time (t) becomes >= grid[i][j] (cell's elevation)
    // You are at the top-left cell (0,0) and you want to reach bottom-right(n-1,n-1).
    // One thing that is very important to notice here is that to even reach the starting cell (0,0), the time(t) must be >= grid[0][0].

    // Procedure:-
    // We initially at the starting will have a visited matrix marked as 0 on each cell except at the start and we will have a priority queue with queue initialized as {grid[0][0],0,0} -> {elevation,row,col}.
    // Important thing to notice here the elevation is the minimum elevation (analogically same as the minimum time) needed to reach (row,col) cell.
    // Now we start with dijkstra and apply loop till priority queue is empty. 
    // Start from the top-left cell of the grid. At each step, choose the cell with the lowest elevation among all reachable, unvisited cells.(This is where the priority queue (min_heap) helps us).
    // As you move, keep track of the highest elevation you've had to cross so far.
    // The goal is to reach the bottom-right cell while keeping this highest elevation as low as possible.
    // Always expand your path from the lowest available elevation to simulate the rising water level.
    // Once you reach the destination, the highest elevation encountered on that path is the minimum time needed to swim across.

    int n = grid.size();

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> vis(n,vector<int>(n,0)); // {elevation,x,y}
    vis[0][0] = 1;
    pq.push({grid[0][0],{0,0}});
    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int e = it.first; // elevation
        int row = it.second.first;
        int col = it.second.second;
        if(row==n-1 && col==n-1) return e;
        for(int i=0; i<4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                int newE = max(e,grid[nrow][ncol]);
                pq.push({newE,{nrow,ncol}});
            }
        }
    }

    return -1;
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
