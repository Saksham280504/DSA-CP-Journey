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
// void solve2() {
//     int x;
//     cin >> x;
//     if(x<=20) cout << (x*10) << endl;
//     else cout << (200 + ((x-20)/2)*5) << endl;
//     // If x is <=20, then cost = x*10;
//     // else cost = 200 + ((x-20)/2)*5;
// }

// Q3
void solve3() {
    int n,x,k;
    cin >> n >> x >> k; 
    // n -> number of participants
    // x -> limit on number of selections
    // k -> number of valid clusters
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    int cnt = 1, ind = 1, prev = arr[0];
    while(cnt<=k && ind<n) {
        if(arr[ind]==prev) {
            ind++;
            continue;
        }
        cnt++;
        prev = arr[ind];
        if(cnt>k) break;
        ind++;
    }
    cout << ((x>=ind) ? ind : x) << endl;
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
    while(t--) solve3();
    return 0;
}
