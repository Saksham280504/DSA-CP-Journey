#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // Intuition -> The idea behind the problem is to sweep through all project start/end events chronologically, and maintain the best total reward obtainable from projects that have already finished.

    // Suppose we are currently at the start of some project, then the projects we can combine with that project are only those that have already finished before this project's start.

    // Terminology and meaning - 
    // mp[i] -> The maximum reward we could have earned before the project i starts.
    // mx -> Maximum total reward achievable using projects that have already ended at the current point in the sweep.
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> pos;
    // ({{pos,start/end},idx}) -> We use this to traverse through project's start/end events chronologically.
    vector<long long> val(n);
    map<int,long long> mp;
    for(int i=0; i<n; i++) {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        val[i] = c;
        pos.push_back({{a,0},i});
        pos.push_back({{b,1},i});
    }
    sort(pos.begin(), pos.end());
    long long mx = 0;
    for(auto &[x,y]: pos) {
        if(x.second==0) { // start
            mp[y] = mx;    
        }
        else {
            mx = max(mx, mp[y]+val[y]);
            // When an end event is encountered, we just see whether taking this project into account will increase our maximum total award or not. If yes, then take it otherwise don't
        }
    }
    cout << mx << endl;

    return 0;
}
