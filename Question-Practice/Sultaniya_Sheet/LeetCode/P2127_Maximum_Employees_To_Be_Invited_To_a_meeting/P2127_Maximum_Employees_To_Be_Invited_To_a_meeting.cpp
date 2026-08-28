#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n,0);
        for(int fav: favorite) {
            indegree[fav]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(!indegree[i]) q.push(i);
        }
        vector<int> maxChain(n,0);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int v = favorite[u];
            maxChain[v] = max(maxChain[v], maxChain[u]+1);
            if(--indegree[v]==0) q.push(v);
        }

        vector<bool> vis(n,false);
        int sum_2_cycle = 0;
        int max_cycle_length = 0;
        for(int i=0; i<n; i++) {
            if(indegree[i]>0 && !vis[i]) {
                int curr = i;
                int cycle_length = 0;
                while(!vis[curr]) {
                    vis[curr] = true;
                    cycle_length++;
                    curr = favorite[curr];
                }
                if(cycle_length==2) {
                    sum_2_cycle += (2+maxChain[i]+maxChain[favorite[i]]);
                }
                else {
                    max_cycle_length = max(max_cycle_length,cycle_length);
                }
            }
        }
        return max(sum_2_cycle,max_cycle_length);
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
