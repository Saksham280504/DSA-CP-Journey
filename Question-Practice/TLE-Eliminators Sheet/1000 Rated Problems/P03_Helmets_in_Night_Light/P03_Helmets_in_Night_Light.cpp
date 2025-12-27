#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool static comp(const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
    if(p1.second!=p2.second) return p1.second<p2.second; // Sort is applied on the basis of which resident has lower sharing cost 
    return p1.first>p2.first;
}
void solve() {
    long long n,p;
    cin >> n >> p;
    vector<pair<long long, long long>> club(n);
    for(int i=0; i<n; i++) cin >> club[i].first; // No. of residents to which one guy can share information
    for(int i=0; i<n; i++) cin >> club[i].second; // Cost per share
    sort(club.begin(),club.end(),comp);

    long long cost = p;
    long long already_shared = 1;
    for(int i=0; i<n; i++) {
        long long can_be_shared = club[i].first;
        long long sharing_cost = club[i].second;
        if(sharing_cost>=p) break; // If the resident's cost of sharing was more than or equal to pak Chanek then he could himself distribute the information than him
        if(already_shared+can_be_shared>n) {
            cost += (n-already_shared)*sharing_cost;
            already_shared = n;
            break;
        }
        else {
            cost += can_be_shared*sharing_cost;
            already_shared += can_be_shared;
        }
    }
    cost += p*(n-already_shared);
    cout << cost << endl;
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

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
