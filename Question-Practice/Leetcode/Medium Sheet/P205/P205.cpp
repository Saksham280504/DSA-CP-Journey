#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string originalDigits(string s) {
        vector<int> freq(26,0);
        for(char ch: s) {
            freq[ch-'a']++;
        }
        vector<int> count(10,0);
        count[0] = freq['z'-'a'];
        count[2] = freq['w'-'a'];
        count[4] = freq['u'-'a'];
        count[6] = freq['x'-'a'];
        count[8] = freq['g'-'a'];
        
        count[1] = freq['o'-'a'] - count[2] - count[4] - count[0];
        count[3] = freq['h'-'a'] - count[8];
        count[5] = freq['f'-'a'] - count[4];
        count[7] = freq['s'-'a'] - count[6];
        count[9] = freq['i'-'a'] - count[5] - count[6] - count[8];
        
        string res = "";
        for(int i=0; i<=9; i++) {
            res.append(count[i], '0' + i);
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
