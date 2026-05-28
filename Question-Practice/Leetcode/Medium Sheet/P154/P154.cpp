#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class UnionFind {
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int x) {
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX!=rootY) {
            if(rank[rootX]>rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if(rank[rootX]<rank[rootY]) {
                parent[rootX] = rootY;
            }
            else { // rank[rootX]==rank[rootY]
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        auto uf = UnionFind(n);

        for(auto p: pairs) {
            uf.unite(p[0],p[1]);
        }

        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> component;

        for(int i=0; i<n; i++) {
            int root = uf.find(i);
            component[root].push(s[i]);
        }

        string result = string(n, ' ');

        for(int i=0; i<n; i++) {
            int root = uf.find(i);
            result[i] = component[root].top();
            component[root].pop();
        }

        return result;
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
