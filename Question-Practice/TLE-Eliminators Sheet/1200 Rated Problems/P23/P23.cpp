#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string mex = "";

    for(char ch='a'; ch<='z'; ch++) {
        if(s.find(ch)==string::npos) {
            mex = ch;
            break;
        }
    }

    for(char ch1='a'; ch1<='z'; ch1++) {
        for(char ch2='a'; ch2<='z'; ch2++) {
            string tmp = "";
            tmp.push_back(ch1);
            tmp.push_back(ch2);
            if(mex!="") break;
            if(s.find(tmp)==string::npos) {
                mex = tmp;
                break;
            }
        }
    }

    for(char ch1='a'; ch1<='z'; ch1++) {
        for(char ch2='a'; ch2<='z'; ch2++) {
            for(char ch3='a'; ch3<='z'; ch3++) {
                string tmp = "";
                tmp.push_back(ch1);
                tmp.push_back(ch2);
                tmp.push_back(ch3);
                if(mex!="") break;
                if(s.find(tmp)==string::npos) {
                    mex = tmp;
                    break;
                }
            }
        }
    }

    cout << mex << endl;

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
