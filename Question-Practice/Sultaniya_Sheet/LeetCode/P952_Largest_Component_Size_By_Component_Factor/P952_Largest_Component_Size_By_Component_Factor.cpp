#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Disjoint {
private:
    vector<int> parent;
    vector<int> rank;
    // vector<int> len; // Don't use this as this will also count the factors within the component
public:
    Disjoint(int n) {
        rank.assign(n,0); // rank => [0,0,0,0,.....,0]
        // len.assign(n,1); // len => [1,1,1,1,1.....,1]
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // parent => [0,1,2,3,4,5....,n-1]
    }
    int find(int x) { // Path Compression
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU==rootV) return;
        if(rank[rootU]<rank[rootV]) {
            parent[rootU] = rootV;
            // len[rootV] += len[rootU];
        }
        else if(rank[rootV]<rank[rootU]) {
            parent[rootV] = rootU;
            // len[rootU] += len[rootV];
        }
        else { // rank[rootV]==rank[rootU]
            parent[rootV] = rootU;
            // len[rootU] += len[rootV];
            rank[rootU]++;
        }
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        Disjoint dsu(max_val+1);
        for(int num: nums) {
            for(int factor=2; factor*factor<=num; factor++) {
                if(num%factor==0) {
                    dsu.merge(num,factor);
                    dsu.merge(num,num/factor);
                }
            }
        }

        unordered_map<int,int> count;
        int maxSize = 1; // Atleast the maxSize of any component will be one
        for(int num: nums) {
            int rootPar = dsu.find(num);
            maxSize = max(maxSize, ++count[rootPar]);
        }

        return maxSize;
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

    // We solve this problem using DSU (Disjoint Set Union), as this is a question of dynamic graph generation. Now to avoid the slower TC of finding the HCF between all pair of nodes, we will simply connect the nodes of nums array with their factors and if two nodes from nums share a common factor, they will have a common parent in DSU (will belong to same component), finally we can maintain a hashmap and traverse all nodes in nums, find their parents, increment the component size of that parent, keep track of the maximum size and finally as the loop ends return the maximum size.

    return 0;
}
