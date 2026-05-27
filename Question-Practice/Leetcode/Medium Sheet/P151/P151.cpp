#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> pairs(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')') {
                int j = st.top();
                st.pop();
                pairs[i] = j;
                pairs[j] = i;
            }
        } 
        string str = "";
        int direction = 1;
        // forward -> 1 , backward -> -1
        for(int i=0; i<n; i+=direction) {
            if(s[i]=='(' || s[i]==')') {
                i = pairs[i];
                direction = -direction;
            }
            else str += s[i];
        } 

        return str;

        // If we follow the brute-force method where we use a stack and keep pushing the element until we encounter a ')', where we will pop the elements until st.top() == '(' and then reverse the chunk -> this approach at worst case will take O(n^2) (TLE)
        // Therefore we will simulate this process by using dual traversal mechanism.
        // 1st traversal to create matching pairs of brackets
        // 2nd traversal is to traverse the array using directional mechanism. Here whenever we see a bracket ('(' or ')'), we will move the index i to its matching bracket index pairs[i], reverse the direction. Otherwise just keeping pushing the characters within the str. This simulates the process of string generation but at a TC much lowe than O(N^2)
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
