#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char,int>> dq;
        for(char ch:s) {
            if(dq.empty() || dq.back().first != ch) dq.push_back({ch,1});
            else if(dq.back().second+1==k) dq.pop_back();
            else dq.back().second++;
        }
        string ans = "";
        while(!dq.empty()) {
            auto [ch,cnt] = dq.front();
            dq.pop_front();
            while(cnt--) {
                ans += ch;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
