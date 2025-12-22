#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'


class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> nge(n,0);
        stack<int> st;
        stack<int> st2;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top()<=arr[i]) {
                st2.push(st.top());
                st.pop();
            }
            nge[i] = st.size();
            st.push(arr[i]);
            while(!st2.empty()) {
                st.push(st2.top());
                st2.pop();
            }
        }

        vector<int> ans;
        for(auto it: indices) {
            ans.push_back(nge[it]);
        }

        return ans;
    }

    // This solution will give runtime error, the problem is not solvable by monotonic stack, it will be solved using merge sort.
};

// This problem is incomplete for now. Go to gfg, study the most optimised solution from there and then try this problem

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
