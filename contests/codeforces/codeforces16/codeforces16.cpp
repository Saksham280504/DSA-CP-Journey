#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve1() {
    long long x;
    cin >> x;
    if(x<10) {
        cout << 0 << endl;
    }
    else if(x%9LL==0 && x%90LL!=0) {
        cout << 10 << endl;
    }
    else cout << 0 << endl;
}

void solve2() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<pair<int,int>> a(n+1,{-1,-1});

    for(int i=0; i<n; i++) { // O(n)
        cin >> p[i];
    }
    for(int i=0; i<n; i++) { // O(n)
        int nums;
        cin >> nums;
        if(a[nums].first==-1) {
            a[nums].first = i;
            a[nums].second = i;
        }
        else if(a[nums].second+1<i) {
            cout << "NO" << endl;
            return;
        }
        else a[nums].second = i;
    }
    int start = -1;
    int end = -1;
    for(int i=0; i<n; i++) {
        if(a[p[i]].first==-1) continue;
        if(start==-1) {
            start = a[p[i]].first;
            end = a[p[i]].second;
        }
        else if(a[p[i]].first > end+1) {
            cout << "NO" << endl;
            return;
        }
        else {
            end = a[p[i]].second;
        }
    }

    cout << "YES" << endl;
}

void solve3() {
    long long p,q;
    cin >> p >> q;
    if(float(p)/float(q)==float(2)/float(3)) {
        cout << "Bob" << endl;
        return;
    }
    long long x = 1;
    while(true) {
        long long numerator = x*2;
        long long denominator = x*3;
        if(numerator>p || denominator>q) {
            x--;
            break;
        }
        x++;
    }

    long long num = x*2;
    long long deno = x*3;
    long long count1 = p-num;
    long long count2 = q-deno;
    if(count1 == count2) {
        cout << "Bob" << endl;
    }
    else cout << "Alice" << endl;
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
    while(t--) {
        solve1();
    }

    return 0;
}
