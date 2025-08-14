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

    string s;
    cin >> s;

    // I will be given a string containing only parantheses and I have to check if the string is properly balanced or not.

    // For this, I have to check for the last opening encountered, whenever I encounter a closing bracket.

    // The intuition of the problem is that every opening should have a corresponding closing and in the correct order.

    // So, this is why here we will use stack data-structure to store all the openings as stack follows LIFO mechanism.

    stack<char> st;
    int n = s.size();

    for(int i=0; i<n; i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else {
            if(st.empty()) {
                cout << "NOT BALANCED" << endl;
                return 0;
            }
            char ch = st.top();
            if((ch=='[' && s[i]==']')||(ch=='{' && s[i]=='}')||(ch=='(' && s[i]==')')) continue;
            else {
                cout << "NOT BALANCED" << endl;
                return 0;  
            }
        }
    }

    if(st.size()) cout << "NOT BALANCED" << endl;
    else cout << "BALANCED" << endl;

    // TC -> O(N)
    // SC -> O(N/2) (worst case -> Firstly there are contiguous N/2 opening brackets and then there are contiguous N/2 closing brackets)
    return 0;
}
