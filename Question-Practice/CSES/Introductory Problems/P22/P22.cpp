#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    long long k;
    cin >> k;

    long long len = 1;
    long long count = 9;
    long long start_num = 1;

    // Step-1 : Finding the length of the numbers within which kth digit fall
    while(k > (count*len)) {
        k -= (count*len);
        len++;
        count *= 10;
        start_num *= 10;
    }

    // k is now 1-indexed digit from start_num of the desired length of number
    // Step-2 : Finding the exact number in which the kth digit fall
    long long target_num = start_num + (k-1)/len;

    // Step-3 : Finding the exact kth digit within the found number.
    string s = to_string(target_num);
    int digit_idx = (k-1)%len;
    cout << s[digit_idx] << endl;
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

    long long q;
    cin >> q;
    while(q--) solve();

    return 0;
}
