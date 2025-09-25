#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve1() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int numOfOperations = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]==0) cnt1++;
        else if(arr[i]==-1) cnt2++;
    }
    if(cnt2%2==0) numOfOperations += cnt1;
    else numOfOperations += cnt1 + 2;
    cout << numOfOperations << endl;
}

void solve2() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    ll maxi = LONG_MIN;
    for(ll i=0; i<n; i++) {
        if(i==0) maxi = max(abs(arr[i]-arr[i+1]),maxi);
        else if(i==n-1) maxi = max(abs(arr[i]-arr[i-1]),maxi);
        else maxi = max(abs(arr[i]-arr[i-1]), max(abs(arr[i]-arr[i+1]),maxi));
    }
    cout << maxi << endl;
}

void solve3() {
    ll n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<ll> arr1(k+1,0);
    for(int i=0; i<n; i++) {
        if(arr[i]<=k) arr1[arr[i]]++;
    }
    int cnt = 0;
    for(int i=0; i<k+1; i++) {
       if(arr1[i]==0 && i!=k) {
        if(arr1[k]!=0) {
            cnt++;
            arr1[k]--;
        }
        else cnt++;
       }
    }
    cnt += arr1[k];
    cout << cnt << endl;
}

void solve4() {
    ll n;
    cin >> n;
    if(n==0 || 1) {
        cout << 1 << endl;
        return;
    }
    string s;
    cin >> s;
    int start = 0;
    int last = n-1;
    while(start<=last) {
        if(s[start]==s[last]) {
            start++;
            last--;
            continue;
        }
        else if(s[start-1]=s[start] && start>0) {
            start++;
            continue;
        }
        else if(s[last]==s[last+1] && last<n-1) {
            last--;
        }
    }
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
    ll t;
    cin >> t;
    while(t--) {
        solve3();
    }

    return 0;
}
