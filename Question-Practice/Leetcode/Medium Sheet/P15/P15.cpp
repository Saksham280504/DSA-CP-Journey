#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int maxLen = 0;
        int l = 0;
        int r = 0;
        while(r<n) {
            if(mpp.find(s[r])!=mpp.end()) {
                if(mpp[s[r]]>=l) l = mpp[s[r]] + 1;
            }
            maxLen = max(maxLen,r-l+1);
            mpp[s[r]] = r;
            r++;
        }

        return maxLen;
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
