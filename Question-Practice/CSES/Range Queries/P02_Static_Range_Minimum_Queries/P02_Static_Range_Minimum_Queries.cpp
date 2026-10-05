#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

struct SparseTable {
    private:
    vector<vector<int>> st;
    int n;
    public:
    SparseTable(vector<int>& a) {
        n = a.size();
        int max_k = n>0 ? __lg(n)+1 : 1;
        st.assign(max_k,vector<int>(n,1e9)); // Always keep max_k before as while computing row k, memory access across index i are contiguous, which minimizes CPU cache misses.
        for(int i=0; i<n; i++) {
            st[0][i] = a[i]; // For single length subarray, the minimum will be the element itself
        }
        for(int k=1; k<max_k; k++) {
            for(int i=0; i<n; i++) {
                // st[k][i] = min(A[i...i+(2^k)-1])
                st[k][i] = min(st[k-1][i],st[k-1][i+(1<<(k-1))]); // [i...i+(1<<k)-1] => [i....i+(1<<(k-1))-1][i+(1<<(k-1))....i+(1<<k)-1], these two might overlap but doesn't matter because minimum is idempotent.
            }
        }
    }
    int query(int L, int R) {
        int len = R-L+1;
        int k = __lg(len);
        return min(st[k][L],st[k][R-(1<<k)+1]);
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
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    SparseTable st(a);

    while(q--) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        cout << st.query(u,v) << endl;
    }

    return 0;
}
