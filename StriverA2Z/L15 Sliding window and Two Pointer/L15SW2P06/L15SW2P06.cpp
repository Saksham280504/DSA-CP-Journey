#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Maximum Length of substring with atmost k distinct characters

class Solution {
    int longestKSubstr(string& s, int k) {
        int n = s.size();
        int l=0, r=0, maxLen=0;
        map<char,int> mpp;
        while(r<n) {
            mpp[s[r]]++;
            if(mpp.size()>k) {
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            if(mpp.size()<=k) maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;

        // TC -> O(N)
        // SC -> O(k)
    }
};

// Longest substring with exactly k type of unique characters

class Solution {
    int longestKSubstr(string& s, int k) {
        map<char,int> mpp;
        int l=0,r=0,maxLen=0;
        int n = s.size();
        while(r<n) {
            mpp[s[r]]++;
            if(mpp.size()>k) {
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            if(mpp.size()==k) maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
    // TC -> O(N)
    // SC -> O(k)
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
