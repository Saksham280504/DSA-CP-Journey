#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int num_k = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            if(nums[i]<num_k) { // This will only be true when num_k got assigned, that is when we earlier found a value nums[j] > st.top() and that made num_k = st.top(). So here, nums[i] -> 1 and num_k -> 2
                return true;
            }
            while(!st.empty() && nums[i]>st.top()) { // num[i] -> 3 and st.top() -> num_k -> 2
                num_k = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
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
