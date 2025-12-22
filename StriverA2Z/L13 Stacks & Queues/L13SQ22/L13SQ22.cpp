#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // mat[i][j] -> i knows j
        int n = mat.size();
        int top = 0;
        int down = n-1;
        while(top<down) {
            if(mat[top][down]) top++;
            else if(mat[down][top]) down--;
            else {
                top++;
                down--;
            }
        }
        if(top>down) return -1;
        
        // top==down
        for(int i=0; i<n; i++) {
            if(i==top) continue;
            else if(mat[top][i]!=0 || mat[i][top]!=1) return -1; // The celebrity must be known to all but knows noone
        }

        return top;

        // TC -> O(N+N)
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
