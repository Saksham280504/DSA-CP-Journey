#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        if(n<k) return {};
        vector<int> s_count(26,0);
        vector<int> p_count(26,0);
        vector<int> res;
        for(char ch: p) {
            p_count[ch-'a']++;
        }
        int i=0;
        for(int j=0; j<n; j++) {
            s_count[s[j]-'a']++;
            if(j-i+1<k) continue;
            if(s_count==p_count) res.push_back(i);
            s_count[s[i]-'a']--;
            i++;
        }
        return res;
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
