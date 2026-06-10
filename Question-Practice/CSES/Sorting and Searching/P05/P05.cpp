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
        ll n;
        cin >> n;
        vector<pair<ll,ll>> events;
        for(ll i=0; i<n; i++) {
            ll arrival,departure;
            cin >> arrival >> departure;
            events.push_back({arrival,1});
            events.push_back({departure,-1});
        }

        sort(events.begin(),events.end());

        ll maxCustomer = 0;
        ll customer = 0;
        for(ll i=0; i<2*n; i++) {
            customer += events[i].second;
            maxCustomer = max(customer,maxCustomer);
        }

        cout << maxCustomer << endl;

        return 0;
    }
