#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxLen = INT_MIN;
        int m = wordDict.size();
        for(int i=0; i<m; i++) {
            int size = wordDict[i].size();
            maxLen = max(maxLen,size);
        }
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1,false); // dp[i] -> can substring s[0...i-1] be formed?
        dp[0] = true;
        for(int i=1; i<=n; i++) { // No of char in substring = i [0...i-1]
            for(int j=max(0,i-maxLen); j<i; j++) { // Now here j varies from 0 to i-1 and s[j...i-1] is actually the substring we check is present in wordDict or not, and along with that we check whether whether a substring s[0....j-1] possible by checking dp[j].
                if(dp[j] && st.count(s.substr(j,i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
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
