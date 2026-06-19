#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

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
    vector<tuple<ll,ll,int>> intervals;
    for(int i=0; i<n; i++) {
        ll arrival, departure;
        cin >> arrival >> departure;
        intervals.emplace_back(arrival,departure,i);
    }
    sort(intervals.begin(),intervals.end());

    vector<int> assigned_room_number(n);
    set<pair<ll,int>> ets_rid;

    auto [curr_arrival, curr_departure, curr_idx] = intervals[0];
    assigned_room_number[curr_idx] = 1;
    ets_rid.emplace(curr_departure, assigned_room_number[curr_idx]);

    for(int i=1; i<n; i++) {
        auto [curr_arrival, curr_departure, curr_idx] = intervals[i];
        auto [min_departure, r_id] = *ets_rid.begin();
        if(min_departure<curr_arrival) {
            ets_rid.erase(ets_rid.begin());
            assigned_room_number[curr_idx] = r_id;
            ets_rid.emplace(curr_departure,r_id);
        }
        else { // min_departure >= curr_arrival
            assigned_room_number[curr_idx] = ets_rid.size()+1;
            ets_rid.emplace(curr_departure,assigned_room_number[curr_idx]);
        }
    }

    cout << *max_element(assigned_room_number.begin(), assigned_room_number.end()) << endl;
    for(int i=0; i<n; i++) cout << assigned_room_number[i] << " ";
    cout << endl;

    return 0;
}
