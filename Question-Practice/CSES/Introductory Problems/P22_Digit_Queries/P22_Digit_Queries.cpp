#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

void solve() {
    ll k;
    cin >> k;

    // Step-1 : Finding the length of the numbers within which kth digit fall    
    ll len = 1; // len[1] = 1, len[99] = 2
    ll count = 9; // count[1..9] = 9, count[10..99] = 90
    ll start_num = 1; // start_num = 1, 10, 100, 1000
    
    while(k>(count*len)) {
        k -= (count*len);
        len++;
        count *= 10;
        start_num *= 10;
    }

    // k is now 1-indexed digit from start_num of the desired length of number

    // Step-2 : Finding the exact number in which the kth digit fall
    ll target_num = start_num + (k-1)/len;

    // Step-3: Find the digit and print
    string target = to_string(target_num);
    ll k_idx = (k-1)%len;
    cout << target[k_idx] << endl;
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
    int q;
    cin >> q;
    while(q--) solve();

    return 0;
}
