#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> ans;
    vector<int> dfs(int node, int parent, vector<int> adjLS[], string& labels) {
        vector<int> freq(26,0);
        freq[labels[node]-'a']++;

        for(auto child: adjLS[node]) {
            if(child==parent) continue;
            vector<int> childFreq = dfs(child,node,adjLS,labels);
            for(int i=0; i<26; i++) {
                freq[i] += childFreq[i];
            }
        }
        ans[node] = freq[labels[node]-'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adjLS[n];
        for(int i=0; i<n-1; i++) {
            adjLS[edges[i][0]].push_back(edges[i][1]);
            adjLS[edges[i][1]].push_back(edges[i][0]);
        }
        ans.resize(n);
        dfs(0,-1,adjLS,labels);
        return ans;
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
