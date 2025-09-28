#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
bool isSsThere(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target==0) return true;
    if(ind==0) return (arr[ind]==target);
    bool notTake = isSsThere(ind-1,target,arr,dp);
    bool take = false;
    if(target>=arr[ind]) take = isSsThere(ind-1,target-arr[ind],arr,dp);
    dp[ind][target] = (take | notTake) ? 1 : 0;
    return dp[ind][target];
}

bool isSsTab(int n, int target, vector<int>& arr, vector<vector<bool>> &dp) {
    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            bool notTake = dp[i-1][k];
            bool take = false;
            if(k>=arr[i]) take = dp[i-1][k-arr[i]];
            dp[i][k] = take | notTake;
        }
    }
    return dp[n-1][target];
}

bool isSsSO(int n, int target, vector<int>& arr){
    vector<bool> prev(target+1,false);
    vector<bool> curi(target+1,false);
    prev[0] = true;
    curi[0] = true;
    prev[arr[0]] = true;

    for(int i=1; i<n; i++) {
        for(int k=1; k<=target; k++) {
            bool notTake = prev[k];
            bool take = false;
            if(k>=arr[i]) take = prev[k-arr[i]];
            curi[k] = take | notTake;
        }
        prev = curi;
    }
    return prev[target];
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
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int sum=0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    if(sum%2!=0) {
        cout << "NOPE" << endl;
        return 0;
    }
    int target = sum/2;

    // Recursive/ Memoization Approach:
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    string isSsPossible = isSsThere(n-1,target,arr,dp) ? "true" : "false";
    cout << isSsPossible << endl;

    // Tabulation Approach:
    vector<vector<bool>> dp1(n, vector<bool>(target+1,false));
    string isSsTabPossible = isSsTab(n,target,arr,dp1) ? "true" : "false";
    cout << isSsTabPossible << endl;

    // Space-Optimization Approach:
    string isSsSOPossible = isSsSO(n,target,arr) ? "true" : "false";
    cout << isSsSOPossible << endl;
    return 0;
}
