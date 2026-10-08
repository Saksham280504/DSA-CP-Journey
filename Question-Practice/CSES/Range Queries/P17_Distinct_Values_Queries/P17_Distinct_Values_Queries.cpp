#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) {
        this->n = n;
        tree.assign(n+1,0);
    }
    void add(int i, int delta) {
        for(int j=i; j<=n; j += (j & (-j))) {
            tree[j] += delta;
        }
    }
    int preSum(int i) {
        int sum = 0;
        for(int j=i; j>0; j -= (j & (-j))) {
            sum += tree[j];
        }
        return sum;
    }
    int query(int L, int R) {
        return preSum(R) - preSum(L-1);
    }
};

struct Query {
    int L;
    int q_id;
    Query(int L, int q_id) {
        this->L = L;
        this->q_id = q_id;
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
    vector<int> a(n+1);
    // Coordinate Compression -> it will help us in flattening the last_pos array size and saving us from using a slower map data structure.
    vector<int> vals;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        vals.push_back(a[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());

    auto get_rank = [&] (int x) -> int {
        return lower_bound(vals.begin(),vals.end(),x) - vals.begin();
    };

    for(int i=1; i<=n; i++) {
        a[i] = get_rank(a[i]); // Instead of storing the values, we store ranks
    }

    vector<vector<Query>> queries_ending_at_r(n+1);
    for(int i=0; i<q; i++) {
        int L,R;
        cin >> L >> R;
        queries_ending_at_r[R].push_back(Query(L,i));
    }
    FenwickTree ft(n);
    vector<int> last_pos(vals.size(),0); // last_pos[val] = 0 -> we haven't encountered this val till now.
    vector<int> ans(q);
    for(int R=1; R<=n; R++) {
        int rank = a[R];
        if(last_pos[rank]!=0) { // If found earlier, remove the earlier occurance significance
            ft.add(last_pos[rank],-1);
        }
        last_pos[rank] = R;
        ft.add(last_pos[rank],1); // Add the present latest significance
        for(auto query: queries_ending_at_r[R]) {
            int L = query.L;
            int i = query.q_id;
            ans[i] = ft.query(L,R);
        }
    }

    for(int x: ans) cout << x << endl;

    return 0;
}
