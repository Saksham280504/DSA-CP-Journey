// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long  => when use this convert int main()  to int32_t main()
// // #define endl '/n'
// #define ll long long

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//    // Write your code here

//    // This is not the correct code for this problem. This code is the standard DP for counting distinct subsequence strings/sequences, where duplicate subsequences should be merged.
// //    const ll mod = 1e9+7;
// //    int n;
// //    cin >> n;
// //    vector<ll> a(n);
// //    for(int i=0; i<n; i++) cin >> a[i];

// //    ll total = 0;
// //    unordered_map<ll,ll> last; 

// //    for(int i=0; i<n; i++) {
// //     ll old_total = total;
// //     ll add = (old_total+1)%mod;
// //     if(last.count(a[i])) {
// //         add = (add-last[a[i]]+mod)%mod;
// //     }
// //     total = (total+add)%mod;
// //     last[a[i]] = (old_total+1)%mod;
// //    }
// //    cout << (total%mod) << endl;

//     // This is the correct code for this problem

//     const ll mod = 1e9+7;
//     int n;
//     cin >> n;
//     vector<ll> a(n);
//     for(int i=0; i<n; i++) cin >> a[i];

//     ll total = 0;
//     unordered_map<ll,ll> bad;

//     for(int i=0; i<n; i++) {
//         ll old_total = total;
//         ll add = (old_total+1)%mod;
//         if(bad.count(a[i])) {
//             add = (add-bad[a[i]]+mod)%mod;
//         }
//         total = (total+add)%mod;
//         bad[a[i]] = (bad[a[i]]+add)%mod;
//     }

//     cout << total << endl;


//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const ll MOD = 1e9 + 7;

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(n), pref(n);
    unordered_map<ll, int> last;

    for (int i = 0; i < n; i++) {

        ll cur = 1;  // subsequence consisting only of a[i]

        if (i > 0) {
            cur = (cur + pref[i - 1]) % MOD;
        }

        if (last.count(a[i])) {
            int p = last[a[i]];

            if (p > 0) {
                cur = (cur - pref[p - 1] + MOD) % MOD;
            } else {
                cur = (cur - 1 + MOD) % MOD;
            }
        }

        dp[i] = cur;

        pref[i] = dp[i];
        if (i > 0) {
            pref[i] = (pref[i] + pref[i - 1]) % MOD;
        }

        last[a[i]] = i;
    }

    cout << pref[n - 1] % MOD << '\n';

    return 0;
}