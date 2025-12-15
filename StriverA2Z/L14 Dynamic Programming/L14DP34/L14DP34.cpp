#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int check(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
    if(ind1==0 && ind2==0) return true;
    if(ind1==0 && ind2>0) return false;
    if(ind2==0 && ind1>0) {
        for(int i=1; i<=ind1; i++) {
            if(s1[i-1]!='*') return false;
        }
        return true;
    }
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1-1]==s2[ind2-1] || s1[ind1-1]=='?') return dp[ind1][ind2] = check(ind1-1,ind2-1,s1,s2,dp);
    if(s1[ind1-1]=='*') return dp[ind1][ind2] = check(ind1-1,ind2,s1,s2,dp) | check(ind1, ind2-1, s1, s2, dp);
    return dp[ind1][ind2] = false;

    // For Recursion:-
    // TC -> Exponential
    // SC -> O(N+M) (Auxillary stack space)

    // For Memoization:-
    // TC -> O(N*M)
    // SC -> O(N*M) + O(N+M)
}

int checkTab(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    dp[0][0] = true;
    for(int j=1; j<=m; j++) dp[0][j] = false;
    for(int i=1; i<=n; i++) {
        int flag = 1;
        for(int ii=1; ii<=i; ii++) {
            if(s1[ii-1]!='*') {
                flag = 0;
                break;
            }
        }
        dp[i][0] = flag;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1] || s1[i-1]=='?') dp[i][j] = dp[i-1][j-1];
            else if(s1[i-1]=='*') dp[i][j] = dp[i-1][j] | dp[i][j-1];
            else dp[i][j] = false;
        }
    }

    return dp[n][m];

    // TC -> O(N*M)
    // SC -> O(N*M)
}

int checkSO(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0);
    prev[0] = true;
    vector<int> curr(m+1,0);

    for(int i=1; i<=n; i++) {
        int flag = 1;
        for(int ii=1; ii<=i; i++) {
            if(s1[ii-1]!='*') {
                flag = 0;
                break;
            }
        }
        curr[0] = flag;
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1] || s1[i-1]=='?') curr[j] = prev[j-1];
            else if(s1[i-1]=='*') curr[j] = prev[j] | curr[j-1];
            else curr[j] = false;
        }
        prev = curr;
    }

    return prev[m];

    // TC -> O(N*M)
    // SC -> O(2N)
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

    // We are given a string s1 and string s2 in which we have to see if s1 matches with s2. s2 contains only alphabets but s1 has alphabets, '?' and '*' as its elements. Now '?' can match with any but only one character whereas '*' can match with any subsequence of size greater than equal to 0.

    // Now in order to be confirm of the size of subsequence that '*' matches with, we need to check all possibilities and therefore we would need to perform recursion.

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    // Recursion/Memoization Approach:
    vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
    if(check(n,m,s1,s2,dp1)) cout << "true" << endl;
    else cout << "false" << endl;

    // Tabulation Approach:-
    vector<vector<int>> dp2(n+1,vector<int>(m+1,0));
    if(checkTab(n,m,s1,s2,dp2)) cout << "true" << endl;
    else cout << "false" << endl;

    // Space-Optimization Approach:-
    if(checkSO(n,m,s1,s2)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
