#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve4() {
    string s;
    cin >> s;
    int n = s.size();
    map<char,int> mpp;
    for(char ch: s) {
        mpp[ch]++;
    }
    int maxCount = 0;
    int maxElement = -1;
    for(auto it: mpp) {
        if(maxCount<it.second) {
            maxCount = it.second;
            maxElement = it.first;
        }
    }
    if(maxCount>n/2) {
        cout << "No" << endl;
        return;
    }
    else {
        cout << "YES" << endl;
        string str = "";
        int cnt = 0;
        if(n%2==0 && maxCount==(n/2)) {
            str += maxElement;
            cnt++;
        }
        while(cnt!=n) {
            for(auto it:mpp) {
                if(it.second!=0) {
                    str += it.first;
                    it.second--;
                    cnt++;
                }
            }
        }
        cout << str << endl;
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

    // Q1
    // int x;
    // cin >> x;
    // x--;
    // string str = "HelloWorld";
    // str.erase(str.begin()+x);
    // cout << str;

    // Q2
    // int n;
    // cin >> n;
    // while(n--) {
    //     string str;
    //     cin >> str;
    //     int c = str[0]-'a'+1;
    //     if(c<=15) {
    //         if(c%3==0) cout << c/3+1;
    //         else cout << c/3+2;
    //     }
    //     else {
    //         if(c<=19) cout << 7;
    //         else if(c<=22) cout << 8;
    //         else cout << 9;
    //     }
    // }

    // Q3
    // int n,q;
    // cin >> n >> q;
    // vector<int> blocks[q];
    // int count = 0;
    // while(q--) {
    //     int type, action;
    //     cin >> type >> action;
    //     if(type==1) {
            
    //     }
    //     else {

    //     }
    // }

    // Q4
    int t;
    cin >> t;
    while(t--) {
        solve4();
    }
    return 0;
}
