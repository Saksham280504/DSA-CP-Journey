#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

// find_by_order, order_of_key: 0 indexed
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// allows duplicate values
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Interval {
    public:
    ll start;
    ll end;
    int index;
    Interval(ll starting, ll ending, int idx) {
        start = starting;
        end = ending;
        index = idx;
    }
};

static bool comparator(Interval& a, Interval& b) {
    if(a.start==b.start) return a.end > b.end;
    return a.start<b.start;
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
    int n;
    cin >> n;
    vector<Interval> intervals;
    for(int i=0; i<n; i++) {
        ll starting, ending;
        cin >> starting >> ending;
        intervals.emplace_back(Interval(starting, ending, i));
    }

    sort(intervals.begin(), intervals.end(), comparator);

    vector<int> is_contained_by_other(n,0);
    vector<int> contains_other(n,0);

    ordered_multiset<ll> ets;

    for(int i=0; i<n; i++) {
        ll current_end = intervals[i].end;
        int curr_idx = intervals[i].index;
        int lb = ets.order_of_key(current_end);
        is_contained_by_other[curr_idx] = i - lb;
        ets.insert(current_end);
    }

    ets.clear();

    for(int i=n-1; i>=0; i--) {
        ll current_end = intervals[i].end;
        ll current_index = intervals[i].index;
        int ub = ets.order_of_key(current_end+1);
        contains_other[current_index] = ub;
        ets.insert(current_end);
    }

    for(int i=0; i<n; i++) cout << contains_other[i] << " ";
    cout << endl;
    for(int i=0; i<n; i++) cout << is_contained_by_other[i] << " ";
    cout << endl;

    return 0;
}
