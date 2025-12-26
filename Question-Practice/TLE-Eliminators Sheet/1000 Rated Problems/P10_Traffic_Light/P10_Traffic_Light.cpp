#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    char curr_light;
    cin >> curr_light;
    string s;
    cin >> s;
    queue<int> q;
    int check = 1;
    for(int i=0; i<n; i++) {
        if(s[i]==curr_light && check==1) { // This will make sure that we only push that index inside the q which is the first comer, thus reducing the TC by a large size
            q.push(i);
            check = 0;
        }
        if(s[i]=='g') { // When enocountered green, it will make check=1, thus we will look for a new curr_light again after an encounter with green
            check = 1;
        }
    }
    // If the curr_light is green
    if(!q.empty() && curr_light=='g') {
        cout << 0 << endl;
        return;
    }

    // If the curr_light is not green
    int maxTime = 0;
    while(!q.empty()) {
        int ind = q.front();
        q.pop();
        for(int i=ind+1; i<2*n; i++) {
            if(s[i%n]=='g') {
                maxTime = max(maxTime,i-ind);
                break;
            }
        }
    }
    cout << maxTime << endl;
    // TC -> O(2N)
    // SC -> O(number of greens) (queue size)
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
        solve();
    }

    return 0;
}
