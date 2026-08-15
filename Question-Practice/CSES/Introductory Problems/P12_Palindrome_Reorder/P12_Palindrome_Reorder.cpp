#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    string str;
    cin >> str;
    int n = str.size();
    map<char,int> mpp;
    for(char ch: str) mpp[ch]++;

    char prev = '#';
    for(auto it: mpp) {
        if((it.second)&1) {
            if(prev=='#') {
                prev = it.first;
            }
            else {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }

    string ans = string(n, ' ');
    if(prev!='#') {
        int idx = n/2;
        ans[idx] = prev;
        mpp[prev]--;
    }
    
    int idx = 0;
    for(auto it: mpp) {
        while(it.second!=0) {
            ans[idx] = it.first;
            ans[n-1-idx] = it.first;
            it.second -= 2;
            idx++;
        }
    }

    cout << ans << endl;

    return 0;
}
