#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long 

// Steps to define ordered_set(PBDS)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_multiset = tree<T,null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


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
    ordered_set<pair<ll,int>> wnd;
    ll inversionPairs = 0;
    int i=0;
    for(int j=0; j<n; j++) {
        // Insert
        wnd.insert({arr[j],j});
        inversionPairs += (wnd.size()-1-wnd.order_of_key({arr[j],j}));
        if(j-i+1<k) continue;
        cout << inversionPairs << endl;
        // Delete
        inversionPairs -= wnd.order_of_key({arr[i],i});
        wnd.erase({arr[i],i});
        i++;
    }
    cout << endl;
    
    return 0;
}
