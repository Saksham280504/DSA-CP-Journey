#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = "";
        for(int i=n-1; i>=0; i--) t += s[i];
        vector<int> prev(n,0);
        for(int j=0; j<n; j++) {
            if(j==0) prev[j] = (s[0]==t[j]);
            else if(s[0]==t[j]) prev[j] = 1;
            else prev[j] = prev[j-1];
        }

        for(int i=1; i<n; i++) {
            vector<int> curr(n,0);
            for(int j=0; j<n; j++) {
                if(s[i]==t[j]) {
                     curr[j] = 1;
                     if(i-1>=0 && j-1>=0) curr[j] += prev[j-1];
                } 
                else {
                    int sdec = 0;
                    int tdec = 0;
                    if(i-1>=0) sdec = prev[j];
                    if(j-1>=0) tdec = curr[j-1];
                    curr[j] = max(sdec,tdec);
                }
            }

            prev = curr;
        }

        return prev[n-1];
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
