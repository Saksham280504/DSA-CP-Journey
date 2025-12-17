#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
      public:
        long long solve(vector<int>& bt) {
            // Shortest Job First Policy: The SJF policy is the scheduling policy of selecting waiting times by executing the processes with minimum execution time first.
            sort(bt.begin(), bt.end()); // Now you have the processes in increasing order of execution time
            long long timer = 0;
            long long waiting = 0;
            for(auto it: bt) {
                waiting += timer; // This avoids us the space complexity of storing all the waiting times first and then adding them
                timer += it;
            }
            int n = bt.size();
            return waiting/n;
        }
        // TC -> O(NlogN + N)
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
