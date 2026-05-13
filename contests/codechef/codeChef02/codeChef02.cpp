#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
// void solve1() {
//     int x,y,z;
//     cin >> x >> y >> z;
//     int rem = (x+z-y);
//     cout << ((rem<0) ? 0 : rem + 1) << endl;
// }

// Q2
void solve2() {
    int x;
    cin >> x;
    if(x<=20) cout << (x*10) << endl;
    else cout << (200 + ((x-20)/2)*5) << endl;
    // If x is <=20, then cost = x*10;
    // else cost = 200 + ((x-20)/2)*5;
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
    int t;
    cin >> t;
    while(t--) solve2();
    return 0;
}
