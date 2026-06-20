#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
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
    if(a.start==b.start) return a.end>b.end;
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
        intervals.emplace_back(Interval(starting,ending,i)); // We used emplace_back() instead of push_back(), because we are generating the input here using Interval(starting,ending,i) rather than using intervals.push_back({starting,ending,i}) as emplace_back() takes lesser TC than push_back() functionality for generating inputs within a vector.
    }

    sort(intervals.begin(), intervals.end(), comparator);

    vector<int> is_contained_by_other(n,0);
    vector<int> contains_other(n,0);

    ll max_end_so_far = LLONG_MIN;
    for(int i=0; i<n; i++) {
        // auto [curr_start,curr_end,idx] =intervals[i]; This will not work as Interval is a user-defined constructor and not an aggregate constructor 
        ll curr_end = intervals[i].end;
        ll curr_index = intervals[i].index;
        if(max_end_so_far!=LLONG_MIN && max_end_so_far>=curr_end) {
            is_contained_by_other[curr_index] = 1;
        }
        max_end_so_far = max(max_end_so_far,curr_end);
    }

    ll min_end_so_far = LLONG_MAX;
    for(int i=n-1; i>=0; i--) {
        ll curr_end = intervals[i].end;
        ll curr_index = intervals[i].index;
        if(min_end_so_far!=LLONG_MAX && min_end_so_far<=curr_end) {
            contains_other[curr_index] = 1;
        }
        min_end_so_far = min(min_end_so_far,curr_end);
    }

    for(int i=0; i<n; i++) cout << contains_other[i] << " ";
    cout << endl;
    for(int i=0; i<n; i++) cout << is_contained_by_other[i] << " ";
    cout << endl;
    
    return 0;
}
