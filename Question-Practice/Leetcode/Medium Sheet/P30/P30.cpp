#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reach(n,vector<bool>(n,false));
        for(auto &p: prerequisites) {
            reach[p[0]][p[1]] = true;
        }

        // Floyd-Warshall for indirect prerequisites
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(reach[i][k] && reach[k][j]) reach[i][j] = true;
                }
            }
        }

        vector<bool> ans;

        for(auto q: queries) {
            ans.push_back(reach[q[0]][q[1]]);
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
