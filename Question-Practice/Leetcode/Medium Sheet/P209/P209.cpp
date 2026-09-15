#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> adjMat(n,vector<int>(n,1e9));
    for(auto &e: edges) {
        int u = e[0];
        int v = e[1];
        int wt = e[2];
        adjMat[u][v] = adjMat[v][u] = wt;
    }

    for(int i=0; i<n; i++) adjMat[i][i] = 0;

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(adjMat[i][k]!=1e9 && adjMat[k][j]!=1e9) {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
    }

    int cityNo = -1;
    int mini = INT_MAX;
    for(int i=0; i<n; i++) {
        int cities = 0;
        for(int j=0; j<n; j++) {
            if(adjMat[i][j]<=distanceThreshold && i!=j) cities++;
        }
        if(cities<=mini) {
            cityNo = i;
            mini = cities;
        }
    }

    return cityNo;
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
