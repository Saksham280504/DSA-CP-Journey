#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
ll numOfWays(int i, int j, int isTrue, string& s, vector<vector<vector<ll>>>& dp) {
    if(i>j) return 0;
    if(i==j) {
        if(isTrue) return s[i]=='T';
        else return s[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    ll ways = 0;
    for(int ind=i+1; ind<=j-1; ind = ind+2) {
        ll lt = numOfWays(i,ind-1,1,s,dp);
        ll lf = numOfWays(i,ind-1,0,s,dp);
        ll rt = numOfWays(ind+1,j,1,s,dp);
        ll rf = numOfWays(ind+1,j,0,s,dp);
        if(s[ind]=='&') {
            if(isTrue) ways = (ways + (lt*rt));
            else ways = (ways + (lt*rf) + (lf*rt) + (lf*rf));
        }
        else if(s[ind]=='|') {
            if(isTrue) ways = (ways + (lt*rf) + (lf*rt) + (lt*rt));
            else ways = (ways + (lf*rf));
        }
        else if(s[ind]=='^') {
            if(isTrue) ways = (ways + (lt*rf) + (lf*rt));
            else ways = (ways + (lt*rt) + (lf*rf));
        }
    }

    return dp[i][j][isTrue] = ways;

    // Recursive Solution -> TC -> Exponential
    // Memoization Solution -> TC -> O(N*N*2)*N -> O(N^3)
    // SC -> O(2N^2) + Auxillary Stack Space (O(N))
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

    // Recursive/Memoization Solution:
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    ll ways = numOfWays(0,n-1,1,s,dp);
    cout << ways << endl;
    return 0;
}
