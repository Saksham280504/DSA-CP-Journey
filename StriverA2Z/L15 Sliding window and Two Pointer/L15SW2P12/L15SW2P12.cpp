#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l=0, r=0, minLen=1e9, startInd=-1, cnt=0;
        vector<int> hash(256,0);
        for(auto it: t) hash[it]++;
        while(r<n) {
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==m) {
                if(hash[s[l]]==0) cnt--;
                if((r-l+1)<minLen) {
                    minLen = r-l+1;
                    startInd = l;
                }
                hash[s[l]]++;
                l++;
            }
            r++;
        }

        return startInd==-1 ? "" : s.substr(startInd,minLen);
        // TC -> O(2N+M)
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
