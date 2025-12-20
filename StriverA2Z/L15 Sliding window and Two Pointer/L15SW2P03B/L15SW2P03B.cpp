#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        vector<int> hash(256,-1);
        int n = s.size();
        int maxLen=0, l=0, r=0;
        while(r<n) {
            if(hash[s[r]]!=-1 && hash[s[r]]>=l) l = hash[s[r]]+1;
            maxLen = max(maxLen,r-l+1);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
        // TC -> O(N)
        // SC -> O(256)
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
