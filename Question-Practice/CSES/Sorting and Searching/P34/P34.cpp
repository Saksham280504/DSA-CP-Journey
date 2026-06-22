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
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> times(n);
    for(int i=0; i<n; i++) {
        cin >> times[i].second >> times[i].first; // {end,start}
    }
    sort(times.begin(),times.end()); // For watching the maximum number of movies we want the movies ending as early as possible to be attended first;

    int cnt = 1; // First movie having the smallest ending time will definitely be watched
    multiset<ll> ets;
    ets.insert(times[0].first);

    for(int i=1; i<n; i++) {
        auto [curr_end, curr_start] = times[i];
        auto it = ets.upper_bound(curr_start);
        if(it==ets.begin()) { // All currently being watched movies will end after the current_movie_starting_time.
            if(ets.size()<k) { // If the number of members watching movies is equal to k, then there is no one available at the moment to watch this current movie. So PASS.
                ets.insert(curr_end);
                cnt++;
            }
        }
        else { // There are some movies which end before or at the current_movie_starting_time
            it--;
            ets.erase(it); // Remove the movie with the largest ending time smaller than equal to the current_movie_starting_time, we will use that member to watch the current movie. The reason being we are taking the closest ending movie is because the movies are sorted as per their ending timme, this means that there is a possibility in the future of a movie which has a highly smaller starting_time, in order for us to create the maximum possibility to attend that movie we want to keep the guys free for which the guys whose movie end early must be kept reserved to use them in the future for circumstances like these.
            ets.insert(curr_end);
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
