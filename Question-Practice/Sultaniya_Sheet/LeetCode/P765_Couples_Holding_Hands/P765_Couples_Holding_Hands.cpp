#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size()/2;
        // row[i] -> stores which person is on the ith position
        vector<int> pos(2*n,-1); // stores the position of the person
        for(int i=0; i<2*n; i++) {
            pos[row[i]] = i;
        }
        int swaps = 0;
        for(int i=0; i<2*n; i+=2) { // i-> 0,2,4,...,2*n-2
            int partner = row[i]^1; // (i+1)^1 -> i, (i)^1 -> i+1, for all i=0,2,4,6,8.....
            if(row[i+1]!=partner) {
                swaps++;
                int partner_idx = pos[partner];
                swap(row[i+1],row[partner_idx]);
                pos[row[partner_idx]] = partner_idx;
                pos[partner] = i+1;
            }
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
