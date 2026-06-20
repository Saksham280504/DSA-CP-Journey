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
    sort(intervals.begin(),intervals.end()); // The incoming guest will need a room immediately as he/she arrives, so we need to sort the intervals by their time of arrival.

    vector<int> assigned_room_number(n); // This will store what room number was provided to the guest.
    set<pair<ll,int>> ets_rid; // This will store {departure_time, provided room} in increasing order

    auto [curr_arrival, curr_departure, curr_idx] = intervals[0];
    assigned_room_number[curr_idx] = 1; // The first guest will get the 1st room.
    ets_rid.emplace(curr_departure, assigned_room_number[curr_idx]);

    for(int i=1; i<n; i++) {
        auto [curr_arrival, curr_departure, curr_idx] = intervals[i]; 
        auto [min_departure, r_id] = *ets_rid.begin();
        // For every current guest, look if the earliest leaving guest has departure time smaller than the arrival time of the current guest.
        if(min_departure<curr_arrival) { // If yes, provide him/her that room
            ets_rid.erase(ets_rid.begin());
            assigned_room_number[curr_idx] = r_id;
            ets_rid.emplace(curr_departure,r_id);
        }
        else { // min_departure >= curr_arrival -> If no, then that means we need to provide this current guest a new room.
            assigned_room_number[curr_idx] = ets_rid.size()+1;
            ets_rid.emplace(curr_departure,assigned_room_number[curr_idx]);
        }
    }

    cout << *max_element(assigned_room_number.begin(), assigned_room_number.end()) << endl;
    for(int i=0; i<n; i++) cout << assigned_room_number[i] << " ";
    cout << endl;

    return 0;
}
