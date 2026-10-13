#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

#define ll long long
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<ll> maskCount((1<<10),0);
        // maskCount[mask] -> number of occurances of mask
        // (1010100100) -> {a,b,d,e,g,i} -> even occurances, {c,f,h,j} -> odd occurances
        maskCount[0] = 1; // empty prefix
        int currMask = 0;
        ll ans = 0;
        for(char c: word) {
            currMask ^= (1<<(c-'a')); // toggle between odd and even parity
            // Even occurances of all
            ans += maskCount[currMask];
            // Odd occurances of only 1 alphabet
            for(int bit=0; bit<10; bit++) {
                ans += maskCount[currMask^(1<<bit)];
            }
            maskCount[currMask]++;
        }
        return ans;
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
