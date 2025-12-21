#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<int> hash(3,-1);
        for(int i=0; i<n; i++) {
            hash[s[i]-'a'] = i;
            cnt += 1 + min(hash[0],min(hash[1],hash[2])); 
        }
        return cnt;
    }

    // Intuition:- With every character, there is a substring that ends.x
    // TC -> O(N)
    // SC -> O(1)
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
