#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int mcm(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    for(int k=i; k<j; k++) {
        int steps = arr[i-1]*arr[k]*arr[j] + mcm(i,k,arr,dp) + mcm(k+1,j,arr,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;

    // Recursive approach:
    // TC -> exponential
    
    // Memoization Approach:
    // TC -> O(N*N)*N ~ O(N^3) (N*N-> dp-array , N-> each state has an inner loop of k which for the worst case can go from 1 to n-1, therefor N states)
    // SC -> O(N*N) (dp-array) + O(N) (auxillary stack space)
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

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    // Recursive/Memoization Approach:
    vector<vector<int>> dp1(n,vector<int>(n,-1));
    int mini = mcm(1,n-1,arr,dp1);
    cout << mini << endl;

    return 0;
}
