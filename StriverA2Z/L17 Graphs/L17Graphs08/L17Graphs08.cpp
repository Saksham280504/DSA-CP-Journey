#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, vector<int>& delRow, vector<int>& delCol, int initialColor) {
    int n = image.size();
    int m = image[0].size();
    ans[row][col] = newColor;
    for(int i=0; i<4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==initialColor && ans[nrow][ncol]!=newColor) dfs(nrow,ncol,ans,image,newColor,delRow,delCol,initialColor);
    }
}
vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image;
    vector<int> delRow = {-1,0,1,0};
    vector<int> delCol = {0,1,0,-1};
    dfs(sr,sc,ans,image,newColor,delRow, delCol,initialColor);
    return ans;

    // SC -> O(N*M) (ans matrix) + O(N*M) (recursion stack-space worst case)
    // TC-> O(X) (dfs call occurs for all the 'X' Neighbours) + O(4X) (for loop runs for all the neighbours)
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

    int n,m;
    cin >> n >> m;
    vector<vector<int>> image;

    for(int i=0; i<n; i++) {
        vector<int> arr(m);
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        image.push_back(arr);
    }

    int sr,sc;
    cin >> sr >> sc;
    int newColor;
    cin >> newColor;
    vector<vector<int>> ans = floodfill(image,sr,sc,newColor);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
