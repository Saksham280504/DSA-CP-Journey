#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int maxPoints(int ind, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(ind==0) {
        int maxi = INT_MIN;
        for(int i=0; i<3; i++) {
            if(i!=last) maxi = max(maxi,arr[ind][i]);
        }
        return dp[ind][last] = maxi;
    }
    if(dp[ind][last]!=-1) return dp[ind][last];
    int maxi = INT_MIN;
    for(int i=0; i<3; i++) {
        if(i!=last) {
            int points = arr[ind][i] + maxPoints(ind-1,i,arr,dp);
            maxi = max(points,maxi);
        }
    }
    return dp[ind][last] = maxi;

    // TC -> O(N*4*3)
    // SC -> O(N) (Stack-Space) + O(4*N) (DP-Array)
}

int maxPointsTab(int n, vector<vector<int>> arr) {
    // vector<vector<int>> dp(n,vector<int>(4,0));
    // dp[0][0] = max(arr[0][1], arr[0][2]);
    // dp[0][1] = max(arr[0][2], arr[0][0]);
    // dp[0][2] = max(arr[0][0], arr[0][1]);
    // dp[0][3] = max(arr[0][1], max(arr[0][0],arr[0][2]));

    // for(int day=1; day<n; day++) {
    //     for(int last=0; last<4; last++) {
    //         dp[day][last] = 0;
    //         for(int task=0; task<3; task++) {
    //             if(task!=last) {
    //                 int point = arr[day][task] + dp[day-1][task];
    //                 dp[day][last] = max(dp[day][last],point);
    //             }
    //         }
    //     }
    // }

    // return dp[n-1][3];
    // TC -> O(N*4*3)
    // SC -> O(4*N)

    vector<int> prev(4);
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][2], arr[0][0]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max(arr[0][0], max(arr[0][1],arr[0][2]));

    for(int day=1; day<n; day++) {
        vector<int> temp(4,0);
        for(int last=0; last<4; last++) {
            temp[last] = 0;
            for(int task=0; task<3; task++) {
                if(task!=last) temp[last] = max(temp[last], arr[day][last] + prev[task]);
            }
        }
        prev = temp;
    }

    return prev[3];

    // TC -> O(N*4*3)
    // SC -> O(4) ≈ O(1)
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
    vector<vector<int>> arr;
    for(int i=0; i<n; i++) {
        vector<int> temp(3);
        for(int j=0; j<3; j++) {
            cin >> temp[j];
        }
        arr.push_back(temp);
    }
    vector<vector<int>> dp(n,vector<int>(4,-1)); // Declaration and Entering of data (here, -1) in a 2-D Array.

    // Recursive/Memoization Approach:
    int maxiPoints = maxPoints(n-1,3,arr,dp);
    cout << maxiPoints << endl;

    // Tabulation Approach:
    // int maxTabPoints = maxPointsTab(n,arr);
    // cout << maxTabPoints << endl;

    // Space-optimized Approach:
    int spaceMaxPoints = maxPointsTab(n,arr);
    
    return 0;
}
