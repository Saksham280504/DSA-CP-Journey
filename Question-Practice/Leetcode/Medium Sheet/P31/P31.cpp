#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Brute-force -> TC -> O(N*M)
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n = haystack.size();
//         int m = needle.size();
//         if(m>n) return -1;
//         int l = 0, r = m-1;
//         string s = "";
//         for(int i=0; i<m; i++) {
//             s += haystack[i];
//         }
//         while(r<n) {
//             if(s==needle) return l;
//             s.erase(s.begin());
//             l++;
//             r++;
//             if(r<n) s += haystack[r];
//         }

//         return -1;
//     }
// };

class Solution {
    private:
    vector<int> lpsmaker(string& pattern) {
        int m = pattern.size();
        vector<int> lps(m,0);
        int len = 0;
        for(int i=1; i<m;) {
            if(pattern[i]==pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if(len!=0) {
                    len = lps[len-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(m==0) return 0;
        vector<int> lps = lpsmaker(needle);
        int i=0, j=0;
        while(i<n) {
            if(haystack[i]==needle[j]) {
                i++;
                j++;
            }
            if(j==m) {
                return i-j;
            }
            else if(i<n && haystack[i]!=needle[j]) {
                if(j!=0) {
                    j = lps[j-1];
                }
                else {
                    i++;
                }
            }
        }

        return -1;
    }

    // We used LPS + KMP mechanism to solve this problem. TC -> O(n+m)
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
