#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

struct Movie {
    int start;
    int end;
};

bool static sortByEndTime(const Movie& a, const Movie& b) {
    return a.end < b.end;
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
    if(!(cin >> n)) return 0;
    vector<Movie> timings(n);
    for(int i=0; i<n; i++) {
        cin >> timings[i].start >> timings[i].end;
    }

    sort(timings.begin(), timings.end(), sortByEndTime);

    ll prev_end_time = 0;
    ll max_movies = 0;
    
    for(int i=0; i<n; i++) {
        if(timings[i].start>=prev_end_time) {
            max_movies++;
            prev_end_time = timings[i].end;
        }
    }
    
    cout << max_movies << endl;

    return 0;
}
