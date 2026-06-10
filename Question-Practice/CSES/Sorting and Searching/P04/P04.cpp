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
    ll n,m;
    cin >> n >> m;
    multiset<ll> tickets;

    for(ll i=0; i<n; i++) {
        ll ticket;
        cin >> ticket;
        tickets.insert(ticket);
    }

    for(int i=0; i<m; i++) {
        int price;
        cin >> price;
        auto it = tickets.upper_bound(price); // This will give me the smallest iterator at which the ticket_price > max_price 
        if(it==tickets.begin()) { // The cheapest ticket is also expensive than the max_price.
            cout << -1 << endl;
        }
        else {
            it--; // This will give the iterator for which the price of the ticket is as close to the price said and is also smaller than that.
            cout << *it << endl;
            tickets.erase(it);
        }
    }


    return 0;
}
