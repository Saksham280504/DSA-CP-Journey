#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n

// Key idea -> For permutations, the frequency of occurance of elements remain same.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n>m) return false;
        vector<int> freq1(26,0), freq2(26,0);
        for(char c: s1) {
            freq1[c-'a']++;
        }
        for(int i=0; i<n; i++) { // s2[0...n-1]
            freq2[s2[i]-'a']++;
        }

        if(freq1==freq2) return true;
        for(int i=n; i<m; i++) {
            freq2[s2[i]-'a']++; // Increment the new char frequency
            freq2[s2[i-n]-'a']--; // Decrement the initial char frequency
            if(freq1==freq2) return true;
        }

        return false;

        // TC -> O(N+M)
        // SC -> O(26) -> O(1)
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
