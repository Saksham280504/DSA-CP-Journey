#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt=0;
        string str = "";
        stack<char> st;
        for(char ch: s) {
            if(ch!=')' && ch!='(') st.push(ch);
            else if(ch=='(') {
                st.push(ch);
                cnt++;
            }
            else {
                if(cnt==0) continue;
                st.push(ch);
                cnt--;
            }
        }
        while(!st.empty()) {
            char ch = st.top();
            st.pop();
            if(ch=='(' && cnt>0) {
                cnt--;
                continue;
            }
            str += ch;
        }
        reverse(str.begin(), str.end());
        return str;
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
