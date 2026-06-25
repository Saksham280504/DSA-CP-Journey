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

    ll ls=0, rs=0;
    multiset<ll> left,right;

    auto rebalance = [&] {
        if(left.size()>right.size()) {
            ll v = *left.rbegin();
            ls -= v;
            left.erase(left.find(v));
            rs += v;
            right.insert(v);
        }
        if(right.size()>left.size()+1) {
            ll v = *right.begin();
            rs -= v;
            right.erase(right.find(v));
            ls += v;
            left.insert(v);
        }
    };

    auto add = [&] (ll v) {
        if(!right.empty() && v>=(*right.begin())) {
            rs += v;
            right.insert(v);
        }
        else {
            ls += v;
            left.insert(v);
        }
        rebalance();
    };

    auto rem = [&] (ll v) {
        if(!right.empty() && v>=(*right.begin())) {
            rs -= v;
            right.erase(right.find(v));
        }
        else {
            ls -= v;
            left.erase(left.find(v));
        }
        rebalance();
    };

    auto cost = [&] {
        ll mid = *right.begin();
        return (left.size()*mid) - ls + rs - (right.size()*mid);
    };

    int n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int i=0;
    for(int j=0; j<n; j++) {
        // Insert
        add(arr[j]);
        if(j-i+1<k) continue;
        cout << cost() << " ";
        // Delete
        rem(arr[i]);
        i++;
    }
    cout << endl;

    return 0;
}
