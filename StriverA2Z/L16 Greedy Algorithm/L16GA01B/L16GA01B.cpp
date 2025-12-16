#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = s.size();
        int n = g.size();
        // Step-1 Sort both the arrays
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        // Step-2 Assign a left pointer and a right pointer for the size and greed array
        int l=0,r=0;

        // Step-3 Perform iteration over the 
        
        while(l<m && r<n) {
            if(g[r]<=s[l]) r++; // Greed of the child is satisfied
            l++;
        }

        return r;

        // TC -> O(NlogN + MlogM + min(M,N))
        // SC -> O(1)
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
