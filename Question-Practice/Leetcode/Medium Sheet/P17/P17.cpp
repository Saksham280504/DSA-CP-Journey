#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<tuple<int,int,int>> arr; // {arrival, leaving, index}
        for(int i=0; i<n; i++) {
            arr.push_back({times[i][0], times[i][1], i});
        }

        sort(arr.begin(), arr.end());

        priority_queue<int, vector<int>, greater<int>> FreeChair;
        for(int i=0; i<n; i++) FreeChair.push(i); // This will contain all the freeChairs available for the coming guests to sit in increasing order, so that the guest always sit on the smallest index free chair.

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occupied; // {leave time, index}
        for(auto &[arrival, leave, index]: arr) {
            
            while(!occupied.empty() && occupied.top().first<=arrival) {
                FreeChair.push(occupied.top().second);
                occupied.pop();
            }
            // Now we have all the free chairs with us that will be available at the time of arrival

            int chair = FreeChair.top();
            FreeChair.pop();
            if(index==targetFriend) return chair;
            occupied.push({leave, chair});
        }

        return -1;
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

    return 0;
}
