#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int longestSubString(int n, string s) {
    int maxLength = 0;

    for(int i=0; i<n; i++) {
        vector<int> hash(256,0);
        for(int j=i; j<n; j++) {
            if(hash[s[j]]==1) break;
            maxLength = max(maxLength,j-i+1);
            hash[s[j]] = 1;
        }
    }

    return maxLength;

    // TC -> O(N*N)
    // SC -> O(256)
}

int longestSubString2(int n, string s) {
    int l=0, r=0, maxLen=0;
    vector<int> hash(256,-1);
    while(r<n) {
        if(hash[s[r]]!=-1) {
            if(hash[s[r]]>=l) l = hash[s[r]]+1;
        }
        maxLen = max(maxLen,r-l+1);
        hash[s[r]] = r;
        r++;
    }

    return maxLen;
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

    // We have to find the length of the largest substring without repeating characters.

    // Brute-force approach:

    int maxLength = longestSubString(n,s);
    cout << maxLength << endl;

    // Better Approach:
    // Key-Note:- Whenever you are given a problem to find out the length of longest substring or something like that, always first try to solve it with Sliding Window & 2-pointer Approach.

    int maxLength2 = longestSubString2(n,s);
    cout << maxLength2 << endl;

    return 0;
}
