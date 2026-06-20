#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;
        for(int i=0; i<m; i++) {
            if(i<m-1) {
                string row = string(n,'#');
                row[0] = '.';
                grid.push_back(row);
            }
            else {
                string row = string(n,'.');
                grid.push_back(row);
            }  
        }
        return grid;    
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
