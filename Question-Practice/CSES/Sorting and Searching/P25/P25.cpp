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

    int n;
    cin >> n;
    vector<ll> times(n);
    for(int i=0; i<n; i++) cin >> times[i];
    cout << max(accumulate(times.begin(),times.end(),0LL),2*(*max_element(times.begin(),times.end()))) << endl;

    // One reader will start with the longest book, while the other will start with the second longest book and both will read in decreasing order of longevity of a book, meaning there will be no overlap of both readers trying to read the same book at a time. When the second reader completes the smallest book, he will have two options: start reading the longest book immediately or wait for sometime as the first reader is still on the longest book.

    return 0;
}
