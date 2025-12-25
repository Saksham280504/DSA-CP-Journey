#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool static comp(const vector<long long>& arr1, const vector<long long>& arr2) {
    if(arr1[2]!=arr2[2]) return (arr1[2]>arr2[2]);
    return arr1[0]<arr2[0];
}
void solve() {
    long long n,k;
    cin >> n >> k;
    vector<vector<long long>> club(n,vector<long long>(3));
    for(int i=0; i<n; i++) {
        club[i][0] = i+1;
        cin >> club[i][1];
        club[i][2] = club[i][1]%k == 0 ? k : club[i][1]%k;
    }
    sort(club.begin(),club.end(),comp);
    
    for(auto it: club) cout << it[0] << " ";
    cout << endl;
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

    long long t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
