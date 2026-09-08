#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    int countRotations(string s, int k) {
        int ans = 0;
        int n = s.size();
        do {
            int cnt = 0;
            for(int i=0; i<(s.size()-1); i++) {
                if(s[i]==s[i+1]) cnt++;
            }
            if(cnt==k) ans++;
            auto it = s.begin();
            char ch = *it;
            s.erase(it);
            s += ch;
            n--;
        }
        while(n>0);
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
