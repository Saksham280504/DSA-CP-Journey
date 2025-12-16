#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
ll MaxSum(int i, int k, int n, vector<int>& arr, vector<ll>& dp) {
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    ll len = 0;
    ll maxi = INT_MIN;
    ll maxSum = INT_MIN;
    for(int j=i; j<min(i+k,n); j++) {
        len++;
        maxi = max(maxi,(ll)arr[j]);
        ll sum = (len*maxi) + MaxSum(j+1,k,n,arr,dp);
        maxSum = max(maxSum,sum);
    }

    return dp[i] = maxSum;

    // Recursive Approach: TC-> Exponential
    // Memoization Approach: TC-> O(N)*k
    // SC -> O(N) + O(N) (Auxillary stack-space)
}

int MaxSumTab(int n, int k, vector<int>& arr, vector<ll>& dp) {
    // Base case is covered in declaration
    for(int i=n-1; i>=0; i--) {
    ll len = 0;
    ll maxi = INT_MIN;
    ll maxSum = INT_MIN;
    for(int j=i; j<min(i+k,n); j++) {
        len++;
        maxi = max(maxi,(ll)arr[j]);
        ll sum = (len*maxi) + dp[j+1];
        maxSum = max(maxSum,sum);
    }
    dp[i] = maxSum;
    }

    return dp[0];
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
    int k;
    cin >> k;
    // Recursion/Memoization Approach:
    vector<ll> dp1(n,-1);
    int maxi = MaxSum(0,k,n,arr,dp1);
    cout << maxi << endl;

    // Tabulation Approach:
    vector<ll> dp2(n+1,0); // Base-Case (dp[n]=0) handled
    int maxi2 = MaxSumTab(n,k,arr,dp2);
    cout << maxi2 << endl;
    return 0;
}
