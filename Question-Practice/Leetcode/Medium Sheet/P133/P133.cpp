#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int lcsSO(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m+1,0);
        for(int i=1; i<=n; i++) {
            vector<int> curr(m+1,0);
            for(int j=1; j<=m; j++) {
                if(text1[i-1]==text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Tabulation Approach:
        return lcsSO(text1, text2);
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
