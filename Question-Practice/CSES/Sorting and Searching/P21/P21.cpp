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

    // We sort the intervals in increasing order of starting, if starting is same then in decreasing order of ending. This will make sure that the preceding interval either starts before the current interval or ends afterwards the current interval, creating more chances of containing the current interval within itself.
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

    ordered_multiset<ll> ets; // We need an ordered multiset because we will use the property of PBDS (order_of_key) to see 2 things:-
    // ets.size() - lb -> this number will tell us that for ith interval how many intervals in the range [0....i-1] has ending times greater than equal to ith interval, as all of them has starting time lesser than equal to the current interval's starting time.
    // ub = ets.order_of_key(curr_end+1) will give us the total number of intervals in the range [i+1...n-1] for the ith interval, which have ending time smaller than equal to the current interval, as all of them have starting time greater than equal to that of the current interval.
    // Also we want the multiset because the ending times can repeat.

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
