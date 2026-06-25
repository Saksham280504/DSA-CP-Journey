#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long 

// These are the required plugins for defining ordered_set and ordered_multiset
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    
    ordered_multiset<ll> wnd;
    int i=0;
    for(int j=0; j<n; j++) {
        // Insert
        wnd.insert(arr[j]);
        if(j-i+1<k) continue;
        cout << *wnd.find_by_order((k-1)/2) << " "; // no matter if the number of elements are even or odd, k-1/2 position will always hold the median (smallest) if elements are sorted.

        // This removal procedure is rather clumsy, its better to use an ordered_set in which you store {element,position} rather than storing element in ordered_multiset.
        wnd.erase(wnd.find_by_order(wnd.order_of_key(arr[i])));
        i++;
    }

    // TC -> O(NlogK)
    // SC -> O(K)

    return 0;
}
