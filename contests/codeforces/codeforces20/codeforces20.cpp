#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

// void solve1() { // My Solution -> Correct
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++) cin >> arr[i];
//     sort(arr.begin(),arr.end());
//     int finalPosition = (((n&1) > 0) ? arr[n/2] : (arr[n/2]+arr[(n/2)-1])/2);
//     int low = 0, high = n-1;
//     int calls = 0;
//     while(low<high) {
//         if(arr[low]==finalPosition && finalPosition==arr[high]) break;
//         calls++;
//         low++;
//         high--;
//     }
//     cout << calls << endl;
// }

void solve1() { // TLE eliminators solution
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<ll,ll> mpp;
    for(int i=0; i<n; i++) mpp[arr[i]]++;
    ll ans = LLONG_MAX;
    ll left = 0;
    for(auto it: mpp) {
        ll count = it.second;
        ll right = n-count-left;
        ans = min(ans,max(left,right));
        left += count;
    }
    cout << ans << endl;
}

void solve2() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll sum = 0, ans = LLONG_MAX;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        ans = min(ans,(sum/(i+1)));
        cout << ans << " ";
    }
    cout << endl;
}

void solve3() { // Regret greedy approach -> V.V.V. Good
    int n,x,s;
    cin >> n >> x >> s;
    string f;
    cin >> f;
    int empty=0, ans=0, ambi=0;
    for(char ch:f) {
        if(ch=='E') {
            if(empty) {
                empty--;
                ans++;
            }
            else if(ambi && x) {
                ambi--;
                x--;
                empty += s;
                ans++;
                empty--;
            }
        }
        else if(ch=='I') {
            if(x>0) {
                x--;
                empty += (s-1);
                ans++;
            }
        }
        else {
            if(empty>0) { // Treat like 'E' but record him just in-case switching in future is needed. An ambivert can switch places because he is always comfortable.
                ambi++;
                ans++;
                empty--;
            }
            else if(x>0) { // An ambivert will only get a new table when there are no other non-empty tables with seats available.
                x--;
                empty += (s-1);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

void solve4() {
    int n,x,s;
    cin >> n >> x >> s;
    string f;
    cin >> f;
    int ans=0, empty=0, ambi=0;
    for(char ch: f) {
        if(ch=='E') {
            if(empty) {
                empty--;
                ans++;
            }
            else if(ambi && x) {
                x--;
                ambi--;
                empty += s;
                ans++;
                empty -= 1;
            }
        }
        else if(ch=='I') {
            if(x) {
                x--;
                empty += (s-1);
                ans++;
            }
        }
        else {
            if(empty) {
                empty--;
                ans++;
                ambi++;
            }
            else if(x) {
                x--;
                empty += (s-1);
                ans++;
            }
        }
    }

    cout << ans << endl;
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
    while(t--) solve4();

    return 0;
}
