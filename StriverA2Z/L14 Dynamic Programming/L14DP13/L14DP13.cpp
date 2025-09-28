#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxChoco(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {

    // Base-Cases:
    if(j1<0 || j2<0 || j1>c-1 || j2>c-1) return -1e8;
    if(i==r-1) {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    // Explore all paths for both Alice & Bob simultaneously!!
    int maxi = -1e8;
    for(int dj1 = -1; dj1<=1; dj1++) {
        for(int dj2 = -1; dj2<=1; dj2++) {
            int value = 0;
            if(j1==j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += maxChoco(i+1,j1+dj1, j2+dj2,r,c,grid,dp);
            maxi = max(maxi,value);
        }
    }

    return dp[i][j1][j2] = maxi;

    // For Recursion Approach:
    // TC -> O((3^R)*(3^R))
    // SC -> O(R) (Recursion Stack-Space)

    // For Memoization Approach:
    // TC -> O(9*(R*C*C))
    // SC -> O(R*C*C) (dp-array) + O(R) (recursion stack-space)
}

int maxChocoTab(int r,int c,vector<vector<vector<int>>>& dp, vector<vector<int>>& grid) {
    for(int j1=0; j1<c; j1++) {
        for(int j2=0; j2<c; j2++) {
            if(j1==j2) dp[r-1][j1][j2] = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }
    for(int i=r-2; i>=0; i--) {
        for(int j1=0; j1<c; j1++) {
            for(int j2 = 0; j2<c; j2++) {
                int maxi = -1e8;
                for(int dj1 = -1; dj1<=1; dj1++) {
                    for(int dj2 = -1; dj2<=1; dj2++) {
                        int value = 0;
                        if(j1 == j2) value += grid[i][j1];
                        else value += grid[i][j1] + grid[i][j2];
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2 >=0 && j2+dj2<c) {
                            value += dp[i+1][j1+dj1][j2+dj2];
                        }
                        else value += -1e8;
                        maxi = max(maxi,value);
                    }
                }
                dp[i][j1][j2] = maxi;   
            }
        }
    }
    return dp[0][0][c-1];
}

int MaxChocoSO(int r, int c, vector<vector<int>>& grid) {

    vector<vector<int>> front(c,vector<int>(c,0));
    vector<vector<int>> curi(c,vector<int>(c,0));

    for(int j1=0; j1<c; j1++) {
        for(int j2=0; j2<c; j2++) {
            if(j1==j2) front[j1][j2] = grid[r-1][j1];
            else front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }
    
    for(int i=r-2; i>=0; i--) {
        for(int j1=0; j1<c; j1++) {
            for(int j2=0; j2<c; j2++) {
                int maxi = -1e8;
                for(int dj1=-1; dj1<=1; dj1++) {
                    for(int dj2=-1; dj2<=1; dj2++) {
                        int value = 0;
                        if(j1==j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        if(j1+dj1>=0 && j1+dj1<c && j2+dj2 >=0 && j2+dj2<c) {
                            value += front[j1+dj1][j2+dj2];
                        }
                        else value += -1e8;
                        maxi = max(maxi,value);
                    }
                }
                curi[j1][j2] = maxi;
            }
        }
        front = curi;
    }

    return front[0][c-1];
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
    int r,c;
    cin >> r >> c;
    vector<vector<int>> grid;

    for(int i=0; i<r; i++) {
        vector<int> temp(c);
        for(int j=0; j<c; j++) {
            cin >> temp[j];
        }
        grid.push_back(temp);
    }

    // Recurive/Memoization Approach:
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    cout << maxChoco(0,0,c-1,r,c,grid,dp) << endl;

    // Tabulation Approach:
    vector<vector<vector<int>>> dp1(r,vector<vector<int>>(c,vector<int>(c,0)));
    cout << maxChocoTab(r,c,dp1,grid) << endl;

    // For space-optimization, we see we can go from a 3D array space to a 2D array space optimization.

    cout << MaxChocoSO(r,c,grid) << endl;

    return 0;
}
