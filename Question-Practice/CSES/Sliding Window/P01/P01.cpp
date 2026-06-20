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
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<ll> arr(n); // Rather than using C++ style array (arr[]) here, we use vector as vector (SC ~ O(10^7)) has much bigger space complexity allowed than arr[] (SC ~ O(10^5)) in local environment. Or you can define arr[] in the global environment where the space complexity restrictions are much loose (SC ~ O(10^7)).

    for(int i=0; i<n; i++) {
        if(i==0) arr[i] = x;
        else arr[i] = ((a*arr[i-1])+b)%c;
    }

    ll tot_xor = 0, w_sum = 0;

    int i=0;
    for(int j=0; j<n; j++) { // i,j represents the left and right end of the window
        w_sum += arr[j];
        if((j-i+1)<k) continue; // First we let the window become of size k
        else { // If the window becomes of size k, then we first take that w_sum and xor it with total xor then move the ith end one element ahead to make the window size k-1.
            tot_xor ^= w_sum;
            w_sum -= arr[i];
            i++;
        }
    }

    cout << tot_xor << endl;

    return 0;
}
