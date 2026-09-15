#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0, r=0, maxLen=0, maxFreq=0;
        vector<int> hash(26,0);
        while(r<n) {
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq,hash[s[r]-'A']);
            if(r-l+1-maxFreq>k) {
                hash[s[l]-'A']--;
                l++;
                maxFreq = max(maxFreq,hash[s[l]-'A']);
            }
            if(r-l+1-maxFreq<=k) {
                maxLen = max(maxLen,r-l+1);
            }
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
