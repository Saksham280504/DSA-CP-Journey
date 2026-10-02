#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> is_sorted(n-1,false);
        int deletes = 0;
        for(int col=0; col<m; col++) {
            bool bad = false;
            for(int i=0; i<(n-1); i++) {
                if(!is_sorted[i] && strs[i][col]>strs[i+1][col]) {
                    bad = true;
                    break;
                }
            }
            if(bad) deletes++;
            else {
                for(int i=0; i<(n-1); i++) {
                    if(strs[i][col]<strs[i+1][col]) is_sorted[i] = true;
                }
            }
        }
        return deletes;
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
