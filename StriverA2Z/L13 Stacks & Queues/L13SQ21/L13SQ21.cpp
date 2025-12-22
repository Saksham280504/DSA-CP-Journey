#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front(); // To make sure that correct window size is followed
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back(); // To apply monotonic stack (decreasing order) on deque
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
        // TC -> O(2N)
        // SC-> O(K + N-K)
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
