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
    priority_queue<pair<int,char>> pq;

    for(int i=0; i<26; i++) {
        if(freq[i]!=0) {
            pq.push({freq[i],'a'+i});
        }
    }

    string ans = "";

    while(pq.size()>=2) {
        auto [cnt1, ch1] = pq.top();
        pq.pop();

        auto [cnt2, ch2] = pq.top();
        pq.pop();

        ans += ch1;
        cnt1--;
        ans += ch2;
        cnt2--;

        if(cnt1>0) pq.push({cnt1,ch1});
        if(cnt2>0) pq.push({cnt2,ch2});
    }

    if(!pq.empty()) {
        auto [cnt, ch] = pq.top();
        if(!ans.empty() && ans.back()==ch) {
            cout << "No" << endl;
            return;
        }
        ans += ch;
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
