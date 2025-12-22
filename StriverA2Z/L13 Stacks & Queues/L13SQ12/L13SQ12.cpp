#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& nums) {
        int m = nums.size();
        vector<int> temp(m,-1);
        stack<int> st;
        for(int i=m-1; i>=0; i--) {
            while(!st.empty() && st.top()>=nums[i]) st.pop();
            temp[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }


        return temp;

        // TC -> O(2N)
        // SC -> O(2N)
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
