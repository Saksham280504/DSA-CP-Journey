#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int mcm(int n, vector<int>& arr, vector<vector<int>> & dp) {
    // Step-1 (Copy the base case)
    for(int i=0; i<n; i++) dp[i][i] = 0;

    // Now in recursion, we follow top-down approach, where we break a bigger problem into smaller problems(base cases) and then combine them to solve the bigger problem
    // But in tabulation we follow the bottom-up approach which means we start from base-cases and then proceed towards the bigger problem.

    // Step-2 (Write the changing states)
    // Step-3 (Copy the Recurrance)

    for(int i=n-1; i>=1; i--) {
        for(int j=i+1; j<n; j++) {
            int mini = 1e9;
            for(int k=i; k<j; k++) {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini,steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
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

    // Here we solve the MCM problem by tabulation approach

    return 0;
}
