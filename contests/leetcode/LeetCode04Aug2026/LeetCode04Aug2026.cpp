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
