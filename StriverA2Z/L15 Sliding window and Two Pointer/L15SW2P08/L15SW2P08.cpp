#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Maximum Length substring with atmost k different characters

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen=0, l=0, r=0, maxFreq=0;
        vector<int> hash(26,0);
        int n = s.size();
        while(r<n) {
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq,hash[s[r]-'A']);
            if(r-l+1-maxFreq>k) {
                hash[s[l]-'A']--;
                l++;
            }
            if(r-l+1-maxFreq<=k) maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }

    // TC -> O(N)
    // SC -> O(1)
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
