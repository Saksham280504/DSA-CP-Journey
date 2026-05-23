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

    // Q1
    // int x;
    // cin >> x;
    // x--;
    // string str = "HelloWorld";
    // str.erase(str.begin()+x);
    // cout << str;

    // Q2
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        int c = str[0]-'a'+1;
        if(c<=15) {
            if(c%3==0) cout << c/3+1;
            else cout << c/3+2;
        }
        else {
            if(c<=19) cout << 7;
            else if(c<=22) cout << 8;
            else cout << 9;
        }
    }
    return 0;
}
