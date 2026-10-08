#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct FenwickTree {
    int n;
    vector<ll> tree;
    FenwickTree(int n) {
        this->n = n;
        tree.resize(n+1);
    }
    void add(int i, ll delta) {
        for(int j=i; j<=n; j += (j & (-j))) {
            tree[j] += delta;
        }
    }
    ll preSum(int i) {
        ll sum = 0;
        for(int j=i; j>0; j -= (j & (-j))) {
            sum += tree[j];
        }
        return sum;
    }

    ll query(int L, int R) {
        if(L>R) return 0;
        return preSum(R) - preSum(L-1);
    }
};

struct Query {
    char type;
    ll a;
    ll b;
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
    vector<ll> salaries(n+1);
    vector<ll> vals;
    for(int i=1; i<=n; i++) {
        cin >> salaries[i];
        vals.push_back(salaries[i]);
    }
    vector<Query> queries(q);
    for(int i=0; i<q; i++) {
        cin >> queries[i].type >> queries[i].a >> queries[i].b;
        if(queries[i].type=='!') {
            vals.push_back(queries[i].b);
        }
        else {
            vals.push_back(queries[i].a);
            vals.push_back(queries[i].b);
        }
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());

    auto get_rank = [&](ll x) -> int {
        return lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;
    };

    int max_rank = vals.size();
    FenwickTree ft(max_rank);

    for(int i=1; i<=n; i++) {
        ft.add(get_rank(salaries[i]),1);
    }

    for(int i=0; i<q; i++) {
        if(queries[i].type=='!') {
            int k = queries[i].a;
            ll val = queries[i].b;
            // Remove the initial salary
            ft.add(get_rank(salaries[k]),-1);
            // Add the new salary
            salaries[k] = val;
            ft.add(get_rank(salaries[k]),1);
        }
        else {
            ll L = queries[i].a;
            ll R = queries[i].b;
            int rank_L = get_rank(L);
            int rank_R = get_rank(R);
            cout << ft.query(rank_L,rank_R) << endl;
        }
    }

    return 0;
}
