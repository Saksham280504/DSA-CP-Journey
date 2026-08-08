#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

const int mod = 1e9 + 7;

struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(int size) {
        n = size; 
        tree.assign(4*n, 0);
    }

    // Point Update: Add 'val' to position 'pos'
    void update(int node, int start, int end, int pos, long long val) {
        if(start==end) {
            tree[node] = (tree[node] + val)%mod;
            return;
        }
        int mid = start + (end-start)/2;
        if(pos<=mid) update(2*node, start, mid, pos, val);
        else update(2*node+1, mid+1, end, pos, val);
        tree[node] = (tree[2*node]+tree[2*node+1])%mod;
    }

    // Range Query: Get sum in range [l,r]
    long long query(int node, int start, int end, int l, int r) {
        if(r<start || end<l) return 0;
        if(l<=start && end<=r) return tree[node];
        int mid = start + (end-start)/2;
        long long left_sum = query(2*node,start,mid,l,r);
        long long right_sum = query(2*node+1,mid+1,end,l,r);
        return (left_sum+right_sum)%mod;
    }

    void add(int pos, long long val) {
        update(1,1,n,pos,val);
    }

    long long queryRange(int l, int r) {
        if(l>r) return 0;
        return query(1,1,n,l,r);
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

    int n;
    if(!(cin >> n)) return 0;
    
    vector<int> a(n);
    vector<int> sorted_a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }

    // Step-1: Coordinate Compression
    sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());
    int m = sorted_a.size();

    SegmentTree segTree(m);
    long long total_subsequences = 0;

    // Step 2: Process elements sequentially
    for(int i=0; i<n; i++) {
        // Map element to its compressed 1-based index
        int rank = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;

        // Query sum of all subsequences ending at values strictly smaller than rank
        long long ways = (1 + segTree.queryRange(1, rank - 1))%mod;

        // Add 'ways' to total result
        total_subsequences = (total_subsequences + ways)%mod;
        
        // Update the segment tree at position 'rank'
        segTree.add(rank,ways);
    }

    cout << total_subsequences << endl;

    return 0;
}
