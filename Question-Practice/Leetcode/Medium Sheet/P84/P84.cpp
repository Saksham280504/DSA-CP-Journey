#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        // Get a count of trailing zeros for all the rows
        int n = grid.size();
        vector<int> trailZeros(n);
        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j]==0) cnt++;
                else break;
            }
            trailZeros[i] = cnt;
        }

        // Greedy placement
        int swaps = 0;
        for(int i=0; i<n; i++) {
            int required = n-1-i;
            int j = i;
            while(j<n && trailZeros[j]<required) j++;
            if(j==n) return -1;
            while(j>i) {
                swap(trailZeros[j],trailZeros[j-1]);
                j--;
                swaps++;
            }

            // There is one very important thing to notice that as we move from i=0->n-1, we are moving in decreasing order of required, thus by finding the closest row(j) such that trailZeros[j]>required will give us the minimum swaps possible to make the grid valid (greedy approach).
        }

        return swaps;
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
