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
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    set<ll> unseen;
    for(int i=0; i<=k; i++) unseen.insert(i);

    map<ll,int> wnd_mp;
    int i=0;
    for(int j=0; j<n; j++) {
        // Insert
        wnd_mp[arr[j]]++;
        if(wnd_mp[arr[j]]==1) unseen.erase(arr[j]);
        if(j-i+1<k) continue;
        cout << *unseen.begin() << endl;
        // Delete
        wnd_mp[arr[i]]--;
        if(wnd_mp[arr[i]]==0) {
            wnd_mp.erase(arr[i]);
            unseen.insert(arr[i]);
        }
        i++;
    }

    return 0;
}
