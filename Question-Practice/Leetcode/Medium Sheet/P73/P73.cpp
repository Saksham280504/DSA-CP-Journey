#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


class Solution {
public:
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

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<ll> dp(n,-1); 
    return MaxSum(0,k,n,arr,dp);
    }
};


class Solution {
    public:
    #define ll long long
    ll maxSumTab(int n, int k, vector<int>& arr, vector<ll>& dp) {
        for(int i=n-1; i>=0; i--) {
            ll len = 0, maxi = LLONG_MIN, maxSum = LLONG_MIN;
            for(int j=i; j<min(i+k,n); j++) {
                len++;
                maxi = max(maxi,(ll)arr[j]);
                ll sum = len*maxi + dp[j+1];
                maxSum = max(maxSum,sum);
            }
            dp[i] = maxSum;
        }
        
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<ll> dp(n+1,0); // base-case dp[n] = 0 handled
        return (int)maxSumTab(n,k,arr,dp);
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
