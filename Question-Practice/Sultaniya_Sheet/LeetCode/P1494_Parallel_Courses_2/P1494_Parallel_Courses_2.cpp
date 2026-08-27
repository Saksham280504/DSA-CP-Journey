#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// class Solution {
// public:
//     int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
//         vector<int> adjLS[n+1];
//         vector<int> indeg(n+1,0);
//         for(auto& rel: relations) {
//             adjLS[rel[0]].push_back(rel[1]);
//             indeg[rel[1]]++;
//         }
//         queue<int> q;
//         for(int i=1; i<=n; i++) {
//             if(indeg[i]==0) q.push(i);
//         }
//         int count = 0;
//         while(!q.empty()) {
//             int sz = q.size();
//             sz = min(sz,k);
//             count++;
//             while(sz--) {
//                 int u = q.front();
//                 q.pop();
//                 for(int v: adjLS[u]) {
//                     indeg[v]--;
//                     if(indeg[v]==0) q.push(v);
//                 }
//             }
//         }
//         return count;
//     }

// This is a greedy approach, which ignores the fact that our current choices may affect the future -> thus dp will be needed and seeing constraints (n<=15), we will use bitmask dp for generating all subsets of courses completed.
// };

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> previous(n,0);
        for(auto &rel: relations) {
            int u = rel[0]-1, v = rel[1]-1;
            previous[v] |= (1<<u);
        }

        vector<int> dp(1<<n, 1e9);
        dp[0] = 0;
        for(int mask=0; mask<(1<<n); mask++) {
            if(dp[mask]==1e9) continue;
            int available = 0;
            for(int i=0; i<n; i++) {
                if(!(mask & (1<<i)) && ((previous[i]&mask)==previous[i])) available |= (1<<i);
            }

            for(int submask=available; submask>0; submask = ((submask-1)&available)) {
                if(__builtin_popcount(submask)<=k) {
                    dp[mask | submask] = min(dp[mask|submask], dp[mask]+1);
                }
            }
        }

        return dp[(1<<n)-1];
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
