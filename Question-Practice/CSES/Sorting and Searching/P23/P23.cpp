#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

bool isPossible(vector<ll>& times, ll nprod_to_make, ll maxT) {
    ll total_products = 0;
    for (auto k : times) {
        total_products += maxT / k; // Here we are running all the machines together and trying to see in maxT time, how much products can we make, if the number of products are greater than t, that means that time can be considered as an answer and we must look for smaller if possible. If products < t, then this time is definitely not the answer and we need to look for bigger times.

        if (total_products >= nprod_to_make) return true; // sice maxT can be 1*10^18 and if k==1 and n=2*10^5, then totalProducts becomes ~ 10^23 which will overflow and t<=10^9, therefore check for everyloop cycle if num_of_prods_to_make >= t
    }
    return false;
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
    cin >> n;
    ll t;
    cin >> t;
    vector<ll> k(n);
    for(int i=0; i<n; i++) cin >> k[i];
    ll ans = -1;
    ll low = 1, high = *max_element(k.begin(), k.end())*t; // The largest time it will take to form t products is to only use the longest time-taking device for making the t products.
    while(low<=high) {
        ll mid = low + (high-low)/2;
        if(isPossible(k,t,mid)) {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << endl;
    return 0;
}
