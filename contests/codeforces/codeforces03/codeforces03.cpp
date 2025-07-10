#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
using ll = long long;

/*
void isTrue(string s){
    int arr[4];
    int t=0;
    for(int i=1; i<=4; i++) {
        arr[i-1] = s[i-1] - 48;
    }
    for(int i=1; i<=4; i++) {
        t = t*10 + arr[i-1];
    }
    int n = sqrt(t);
    double m = sqrt(t);
    if(n!=m) {
        cout << -1 << endl;
        return;
    }
    else if(n%2==0) {
        int a = n/2;
        cout << a << " " << a << endl;
        return;
    }
    else {
        int a = (n-1)/2;
        int b = n-a;
        cout << a << " " << b << endl;
    }
};
*/
/*
void isPossible(string s, int k, int n){
    int counter = 0;
    for(int i=1; i<=n/2; i++) {
        if(s[i-1]==s[n-i]) counter++;
    }
    cout << counter  << " " << k << endl;
}
*/

int doSomething(vector<int>& arr) {
    for(int i=1; i<(arr.end()-arr.begin()); i++){
        if(arr[i] - arr[i-1] <= 1) arr.erase(arr.begin() + i);
    }
    for(int i=1; i<(arr.end()-arr.begin()); i++) {
        if(arr[i] - arr[i-1] <= 1) doSomething(arr);
    }
    int m = arr.end()-arr.begin();
    return m;
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
    for(ll i=1; i<=t; i++) {
       int n;
       cin >> n;
       vector<int> arr(n);
       for(int j=1;j<=n;j++){
        cin >> arr[j-1];
       }
    int m = doSomething(arr);
    cout << m << endl;
    }
    return 0;
}
