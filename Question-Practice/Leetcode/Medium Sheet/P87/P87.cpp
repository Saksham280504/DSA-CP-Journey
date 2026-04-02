#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0; // Total net fuel left after one circuit
        int tank = 0; // Net fuel left from start till i
        int start = 0;

        for(int i=0; i<n; i++) {
            total += gas[i]-cost[i];
            tank += gas[i]-cost[i];

            if(tank<0) { // If for some start, we had an index i such that the tank = sum(gas[j]-cost[j]) for(i=start...i) becomes < 0, then this means that none of the j in [start,i] can become a new start.
                // tank[start,i] <0
                // tank[start,j-1]>=0
                // tank[j,i] = tank[start,i]-tank[start,j-1] < 0
                start = i+1;
                tank = 0;
            }
        }

        return total>=0 ? start : -1;
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
