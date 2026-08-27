#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> time_visited(n,0);
        int current_time = 1;
        int max_cycle = -1;
        for(int i=0; i<n; i++) {
            if(time_visited[i]>0) continue;
            int u = i;
            int start_time = current_time;
            while(u!=-1) {
                if(time_visited[u]>0) {
                    if(time_visited[u]>=start_time) {
                        max_cycle = max(max_cycle,current_time-time_visited[u]);
                    }
                    break;
                }
                time_visited[u] = current_time++;
                u = edges[u];
            }
        }
        return max_cycle;
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
