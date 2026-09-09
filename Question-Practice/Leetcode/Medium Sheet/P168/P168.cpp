#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_seen(26,-1);
        int n = s.size();
        for(int i=0; i<n; i++) {
            char ch = s[i];
            last_seen[ch-'a'] = i;
        }
        stack<char> st;
        vector<bool> seen(26,false);
        for(int i=0; i<n; i++) {
            int ch = s[i]-'a';
            if(seen[ch]) continue;
            while(!st.empty() && st.top()>=s[i] && i<last_seen[st.top()-'a']) {
                seen[st.top()-'a'] = false;
                st.pop();
            }
            seen[ch] = true;
            st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
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
