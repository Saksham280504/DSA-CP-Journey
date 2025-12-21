#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it: s) {
            if(it=='(' || it=='[' || it=='{') st.push(it);
            else {
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if(it==']' && top!='[') return false;
                else if(it=='}' && top!='{') return false;
                else if(it==')' && top!='(') return false;
            }
        }
        return st.empty();

        // TC -> O(N)
        // SC -> O(N)
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
