#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    vector<int> adjLS[n];

    for(auto &c: prerequisites) {
        adjLS[c[1]].push_back(c[0]);
    }

    vector<int> indegree(n,0);

    for(int i=0; i<n; i++) {
        for(auto it: adjLS[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i<n; i++) {
        if(indegree[i]==0) q.push(i); 
    }

    vector<int> topo;

    while(!q.empty()) {
        int node = q.front();
        topo.push_back(node);
        q.pop();

        for(auto it: adjLS[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it); // The indegree must be zero because we want all the prerequisite courses to be finished so that ith course can be taken.
        }
    }

    if(topo.size()!=n) topo.clear();
    return topo;
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
