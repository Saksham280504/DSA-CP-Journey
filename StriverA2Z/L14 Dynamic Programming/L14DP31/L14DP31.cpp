#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int shortestSupSeq(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
    if(ind1==0 || ind2==0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2] =  1 + shortestSupSeq(ind1-1, ind2-1, s1, s2,dp);
    return dp[ind1][ind2] = 0 + max(shortestSupSeq(ind1-1,ind2,s1,s2,dp),shortestSupSeq(ind1, ind2-1, s1, s2,dp));
}

int shortestTab(int n, int m, string s1, string s2, vector<vector<int>>& dp) {
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int length = n+m-dp[n][m];
    int ind = length-1;
    string s3 = "";
    for(int i=0; i<length; i++) s3 += '$';
    int i = n;
    int j = m;

    while(i>0 && j>0) {
        if(s1[i-1]==s2[j-1]) {
            s3[ind--] = s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) {
            s3[ind--] = s1[i-1];
            i--;
        }
        else {
            s3[ind--] = s2[j-1];
            j--;
        }
    }
    while(i>0){ 
        s3[ind--] = s1[i-1];
        i--;
    }
    while(j>0){ 
        s3[ind--] = s2[j-1];
        j--;
    }
    cout << s3 << endl;
    return dp[n][m];
}

int shortestSO(int n, int m, string s1, string s2) {
    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);

    for(int i=1; i<=n; i++) {
        for(int j=1;j<=m; j++) {
            if(s1[i-1]==s2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = 0 + max(prev[j],curr[j-1]);
        }
        prev = curr;
    }

    return prev[m];
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

    // Here we are given two arrays s1 and s2 and we have to generate the shortest Common supersequence of them. This basically refers to a string which has both s1 and s2 as its subsequences.

    // Easiest way is to just paste s2 after s1 (n+m)
    // But in order to generate the shortest possible supersequence we have to follow some other path. We first need to find the largest common subsequence and then we need to paste the characters from s1 and s2 which are not a part of the subsequence while maintaining the order of their occurance.

    // Length of smallest supersequence -> n + m - subsequence

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    // Recursive/Memoization approach:
    vector<vector<int>> dp1(n+1,vector<int>(m+1,-1));
    int length1 = n+m-shortestSupSeq(n,m,s1,s2,dp1);
    cout << length1 << endl;

    // Tabulation Approach:
    vector<vector<int>> dp2(n+1, vector<int>(m+1,0));
    int length2 = n+m-shortestTab(n,m,s1,s2,dp2);
    cout << length2 << endl;

    // Space-Optimization Approach:
    int length3 = n+m-shortestSO(n,m,s1,s2);
    cout << length3 << endl;
    return 0;
}
