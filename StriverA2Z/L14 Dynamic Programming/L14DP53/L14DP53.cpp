#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool isPalindrome(int i, int j, string &s) {
    while(i<j) {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int minOp(int i, int n, string &s, vector<int>& dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int mini = INT_MAX;
    for(int j=i; j<n; j++) {
        if(isPalindrome(i,j,s)) mini = min(mini,1+minOp(j+1,n,s,dp));
    }
    return dp[i] = mini;

    // Recursive Approach:
    // TC -> Exponential
    
    // Memoization Approach:
    // TC -> O(N)*N
    // SC -> O(N) + O(N) (Auxillary stack space)
}

int minOpTab(int n, string &s, vector<int>& dp) {
    for(int i=n-1; i>=0; i--) {
        int mini = INT_MAX;
        for(int j=i; j<n; j++) {
            if(isPalindrome(i,j,s)) mini = min(mini,1+dp[j+1]);    
        }
        dp[i] = mini;
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

    string s;
    cin >> s;
    int n = s.size();

    // Recursive/Memoization Approach:
    vector<int> dp1(n,-1);
    int mini = minOp(0,n,s,dp1)-1;
    cout << mini << endl;

    // Tabulation Approach:
    vector<int> dp2(n+1,0); // Base case (dp[n]=0) handled
    int mini2 = minOpTab(n,s,dp2)-1;
    cout << mini2 << endl;
    return 0;
}
