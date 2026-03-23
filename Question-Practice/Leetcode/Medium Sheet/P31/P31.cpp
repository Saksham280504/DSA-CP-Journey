#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// My solution -> TC -> O(N*M)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m>n) return -1;
        int l = 0, r = m-1;
        string s = "";
        for(int i=0; i<m; i++) {
            s += haystack[i];
        }
        while(r<n) {
            if(s==needle) return l;
            s.erase(s.begin());
            l++;
            r++;
            if(r<n) s += haystack[r];
        }

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
