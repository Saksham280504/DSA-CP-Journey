#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> topoSort(int n, vector<int> adjLS[]) {
    // Works for both single-component graph and graph with components

    // Formation of indegree array
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

    int cnt = 0;
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        cnt++;
        for(auto it: adjLS[node]) {
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    if(cnt!=n) return {}; // If cycle was formed then no order is possible
    return topo;
}
string findOrder(string dict[], int n, int k) {
    vector<int> adjLS[k];

    // Formation of Adjacency List
    for(int i=0; i<n-1; i++) {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.length(),s2.length());
        bool found = false;
        for(int l=0; l<len; l++) {
            if(s1[l]!=s2[l]) {
                adjLS[s1[l]-'a'].push_back(s2[l]-'a');
                found = true;
                break;
            }
        }
        if(!found && s1.length()>s2.length()) return ""; // If s1 has greater size than s2 and if no different letter is found when checked till the length of s2, then s1 must be after s2 but still s1 comes before s2 which proves that no order is possible.
    }

    vector<int> topo = topoSort(k,adjLS);
    if(topo.empty()) return "";
    string ans = "";
    for(auto it: topo) {
        ans += char(it+'a');
    }

    return ans;
}
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
