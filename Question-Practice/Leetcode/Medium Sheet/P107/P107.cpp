#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Brute-force Solution
// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         int q = (b.size()-1)/a.size() + 1;
//         string str = "";
//         for(int i=0; i<q; i++) {
//             str += a;
//         }
//         if(str.find(b)!= string::npos) return q;
//         str += a;
//         if(str.find(b)!= string::npos) return q+1;
//         return -1;
//     }
// };

// Optimal Solution (LPS+KMP approach) -> Since if(str.find(b)!= string::npos) return q; statement takes O(str.length()*b.length()) TC it can lead to TLE in worst case. Therefore, we will use LPS + KMP approach

class Solution {
private:
    vector<int> BuildLPS(string pattern) {
        int n = pattern.size();
        vector<int> lps(n,0);
        int len=0, i=1;
        while(i<n) {
            if(pattern[i]==pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } 
            else {
                if(len!=0) len = lps[len-1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool kmp(string text, string pattern) {
        int i=0,j=0;
        vector<int> lps = BuildLPS(pattern);
        while(i<text.size()) {
            if(text[i]==pattern[j]) {
                j++;
                i++;
            }
            if(j==pattern.size()) return true;
            else if(i<text.size() && text[i]!=pattern[j]) {
                if(j!=0) j = lps[j-1]; // If mismatch occurs, don't start again from j=0, whereas ask "How much pattern is still useful?" -> ans will be lps[j-1] 
                else i++;
            }
        }

        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int q = (b.size()-1)/a.size() + 1;
        string temp = "";
        for(int i=0; i<q; i++) temp += a;
        if(kmp(temp,b)) return q;
        temp += a;
        if(kmp(temp,b)) return q+1;
        return -1;
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
