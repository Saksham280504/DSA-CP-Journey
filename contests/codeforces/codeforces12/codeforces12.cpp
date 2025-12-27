#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for(auto it: s) {
        if(it=='Y') cnt++;
    }
    if(cnt>=2) cout << "NO" << endl;
    else cout << "YES" << endl;
}

// void solve() {
//     string r;
//     cin >> r;
//     int n = r.size();
//     queue<int> q;
//     for(int i=0; i<n; i++) {
//         if(r[i]=='u') q.push(i);
//     }
//     int op = 0;
//     while(!q.empty()) {
//         int it = q.front();
//         q.pop();
//         if(it==0 || it==n-1) {
//             r[it] = 's';
//             op++;
//         }
//         else if(r[it+1]=='u') {
//             q.pop();
//             r[it+1] = 's';
//             op++;
//         }
//     }

//     cout << op << endl;
// }

void solve() {
    int n;
    cin >> n;
    vector<long long> w;
    for(auto &x: w) cin >> x;
    int x = 0;
    for(int cnt=1; cnt<=n-1; cnt++) {
        if(w[0]<-w[1]) {
            x -= w[1];
            w.erase(w.begin()+1);
        }
        else if(w[0]>-w[1]) { 
            x += w[0];
            w.erase(w.begin());
        }
        else { // w[0]==-w[1] (2,-2,...) || (-2,2,..)
            if(w.size()>=3) { // Atleast one more element is there
                if(w[0] >= 0 && w[2]>=0) {
                    x += w[0];
                    w.erase(w.begin());
                }
            }
            else { // (2,-2) || (-2,2)
                x += w[0];
                w.erase(w.begin());
            }
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
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}
