#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class DSU {
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n) {
        rank.assign(n,1);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x) {
        return (parent[x]==x) ? parent[x] : (parent[x]=find(parent[x]));
    }
    void merge(int x, int y) {
        int lx = find(x);
        int ly = find(y);
        if(lx!=ly) {
            if(rank[lx]<rank[ly]) {
                parent[lx] = ly;
            }
            else if(rank[lx]>rank[ly]) {
                parent[ly] = lx;
            }
            else {
                parent[lx] = ly;
                rank[ly]++;
            }
        }
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        auto ds = DSU(n);
        for(auto &swap: allowedSwaps) {
            ds.merge(swap[0],swap[1]);
        }
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<n; i++) {
            int p = ds.find(i);
            mpp[p].push_back(i);
        }
        int hamming_distance = 0;
        for(auto &[leader, indices]: mpp) {
            unordered_map<int,int> count;
            for(int idx: indices) {
                count[source[idx]]++;
            }
            for(int idx: indices) {
                int val = target[idx];
                if(count[val]>0) {
                    count[val]--;
                }
                else hamming_distance++;
            }
        }
        return hamming_distance;
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
