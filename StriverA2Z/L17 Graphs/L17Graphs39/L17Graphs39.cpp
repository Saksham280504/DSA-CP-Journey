#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

    // Making of Adjacency matrix
    vector<vector<int>> adjMat(n,vector<int>(n,1e8));
    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adjMat[u][v] = adjMat[v][u] = wt;
    }

    for(int i=0; i<n; i++) {
        adjMat[i][i] = 0;
    }

    // Floyd Warshall Algorithm
    for(int k=0; k<n; k++) { // via
        for(int i=0; i<n; i++) { // from
            for(int j=0; j<n; j++) { // to
                if(adjMat[i][k]!=1e8 && adjMat[k][j]!=1e8) { // to prevent overflow
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j]);
                }
            }
        }
    }

    // To get minimum neighbour cities of each city as per threshold value
    vector<int> minCities(n);
    int mini = INT_MAX;
    for(int i=0; i<n; i++) {
        int cities = 0;
        for(int j=0; j<n; j++) {
            if(adjMat[i][j]<=distanceThreshold && i!=j) cities++;
        }
        mini = min(mini,cities);
        minCities[i] = cities;
    }
    int ans = -1;
    for(int i=0; i<n; i++) {
        if(minCities[i]==mini) ans = i;
    }
    return ans;

    // TC -> O(N^3)
    // SC -> O(N^2)
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
