#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        // The main intuition is to use Greedy + min_heap approach. Since the ladder can be as long as we want so we will always try to use the ladder for the maximum possible height difference and will use the bricks for the smaller differences.
        // To do this we will assume using ladders for all the positive height differences first and push them in pq. Once pq.size() > ladders, we will use the bricks for pq.top() (smallest height difference), keeping the largest height differences for the ladder.
        priority_queue<int,vector<int>, greater<int>> pq;

        for(int i=0; i<n-1; i++) {
            int climb = heights[i+1]-heights[i];
            if(climb>0) {
                pq.push(climb);
                if(pq.size()>ladders) {
                    bricks -= pq.top();
                    pq.pop();
                    if(bricks<0) return i;
                }
            }
        }

        return n-1;
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
