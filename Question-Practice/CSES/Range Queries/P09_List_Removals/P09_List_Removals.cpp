#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct SegmentTree {
    int n;
    vector<ll> tree;
    public:
    SegmentTree(int n) {
        this->n = n;
        tree.assign(4*n+1,0);
    }

    // Initialize all the leaves with 1 (each element is initially present)
    void build_tree(int node, int L, int R) {
        if(L==R) {
            tree[node] = 1;
            return;
        }
        int mid = L + (R-L)/2;
        build_tree(2*node,L,mid);
        build_tree(2*node+1,mid+1,R);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    // Walk on segment tree: finds the k-th active original index,
    int find_and_remove(int node, int L, int R, int k) {
        if(L==R) {
            tree[node] = 0;
            return L;
        }

        int mid = L + (R-L)/2;
        int left_active = tree[2*node];
        int target_index;

        if(k<=left_active) {
            target_index = find_and_remove(2*node, L, mid, k);
        } else { // k > left_active
            target_index = find_and_remove(2*node+1, mid+1, R, k-left_active);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
        return target_index;
    }

    void build(int root) {
        build_tree(root,1,n);
    }

    int remove_kth(int k) {
        return find_and_remove(1,1,n,k);
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
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    SegmentTree seg(n);
    seg.build(1);

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        int original_idx = seg.remove_kth(k);
        cout << a[original_idx] << " ";
    }
    cout << endl;
    return 0;
}
