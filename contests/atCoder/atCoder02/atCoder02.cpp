#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve4() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26,0);
    for(char x: s) {
        freq[x-'a']++;
    }
    int mx = *max_element(freq.begin(),freq.end());
    if(mx>(n+1)/2) {
        cout << "No" << endl;
        return;
    }
    
    vector<pair<int,char>> pairs;
    for(int i=0; i<26; i++) {
        if(freq[i]>0) {
            pairs.push_back({freq[i],(char)('a'+i)});
        }
    }

    sort(pairs.rbegin(), pairs.rend());

    string sort_s = "";

    for(auto p: pairs) {
        sort_s += string(p.first,p.second);
    }

    string ans = string(n,' ');
    int idx = 0;

    for(int i=0; i<n; i+=2) {
        ans[i] = sort_s[idx++];
    }
    for(int i=1; i<n; i+=2) {
        ans[i] = sort_s[idx++];
    }

    cout << "Yes" << endl << ans << endl;
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
