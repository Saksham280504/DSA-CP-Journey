#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class NeighborSum {
public:
    vector<vector<int>> obj;
    int n;
    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        obj.resize(n);
        for(int i=0; i<n; i++) {
            obj[i].resize(n);
            for(int j=0; j<n; j++) {
                obj[i][j] = grid[i][j];
            }
        }
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        pair<int,int> pii = {-1,-1};
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(obj[i][j]==value) {
                    pii.first = i;
                    pii.second = j;
                    break;
                }
            }
        }
        int i = pii.first, j = pii.second;
        if(i==-1 || j==-1) return sum;
        if(i>0) sum += obj[i-1][j];
        if(j>0) sum += obj[i][j-1];
        if(i<(n-1)) sum += obj[i+1][j];
        if(j<(n-1)) sum += obj[i][j+1];
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;
        pair<int,int> pii = {-1,-1};
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(obj[i][j]==value) {
                    pii.first = i;
                    pii.second = j;
                    break;
                }
            }
        }
        int i = pii.first, j = pii.second;
        if(i==-1 || j==-1) return sum;
        if(i>0) {
            if(j>0) sum += obj[i-1][j-1];
            if(j<n-1) sum += obj[i-1][j+1];
        }
        if(i<n-1) {
            if(j<n-1) sum += obj[i+1][j+1];
            if(j>0) sum += obj[i+1][j-1];
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

// Q2

class Solution {
public:
    vector<vector<int>> adjLS;
    int shortestPath(int n) {
        queue<int> q;
        vector<int> dist(n,1e9);
        q.push(0);
        dist[0] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(u==(n-1)) break;
            for(int v: adjLS[u]) {
                if(dist[v]>dist[u]+1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        adjLS.resize(n);
        for(int u=0; u<n-1; u++) {
            adjLS[u].push_back(u+1);
        }
        int q = queries.size();
        vector<int> ans;
        for(int i=0; i<q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            adjLS[u].push_back(v);
            int sp = shortestPath(n);
            ans.push_back(sp);
        }
        return ans;
    }
};

// Q3
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> active;
        for(int i=0; i<n; i++) active.insert(i);
        int q = queries.size();
        vector<int> ans;
        for(int i=0; i<q; i++) {
            int u = queries[i][0], v = queries[i][1];
            auto it = active.upper_bound(u);
            while(it!=active.begin() && *it<v) {
                it = active.erase(it);
            }
            ans.push_back(active.size()-1);
        }
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

    // 1st Question -> Class Implementation
    // 2nd Question -> BFS (SHORTEST PATH ON UNWEIGHTED GRAPH)
    // 3rd Question -> Graph was dynamic but was not based on DSU, it was simply the realization that once there is a road built between u and v, all the intermediate nodes are not needed as there will be no crossovers.
    // 4th Question -> Fenwick Tree (Abhi Padha nahi hai)
    
    return 0;
}
