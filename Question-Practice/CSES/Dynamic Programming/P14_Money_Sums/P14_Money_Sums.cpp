#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

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
    int TotalSum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        TotalSum += arr[i];
    }

    // 2D DP Solution
    // vector<vector<bool>> dp(n+1,vector<bool>(TotalSum+1,false));
    // // dp[i][j] -> is it possible to generate a sum j with the help of first i elements of arr
    // dp[0][0] = true; // If no elements are present, then it is always possible to generate sum = 0

    // for(int i=1; i<=n; i++) {
    //     int val = arr[i-1];
    //     for(int j=0; j<=TotalSum; j++) {
    //         dp[i][j] = dp[i-1][j];
    //         if(val<=j) dp[i][j] = (dp[i][j] || dp[i-1][j-val]);
    //     }
    // }

    // int total = 0;
    // for(int j=1; j<=TotalSum; j++) {
    //     if(dp[n][j]) total++;
    // }
    // cout << total << endl;
    // for(int j=1; j<=TotalSum; j++) {
    //     if(dp[n][j]) cout << j << " ";
    // }

    // 1D DP Solution
    vector<bool> dp(TotalSum+1,false);
    dp[0] = true;

    for(int i=1; i<=n; i++) {
        int val = arr[i-1];
        for(int j=TotalSum; j>=val; j++) {
            dp[j] = (dp[j] || dp[j-val]);
        }
    }

    int total = 0;
    for(int j=1; j<=TotalSum; j++) {
        if(dp[j]) total++;
    }

    cout << total << endl;

    for(int j=1; j<=TotalSum; j++) {
        if(dp[j]) cout << j << " ";
    }
    cout << endl;

    return 0;
}
