#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int MaxInd = 0;
        int pointer = 0;
        while(pointer<n) {
            if(pointer<=MaxInd) {
                MaxInd = max(pointer + nums[pointer],MaxInd);
                if(MaxInd>=n) return true;
                pointer++;
            }
            else return false;
        }

        return true;
    }

    // TC -> O(N)
    // SC -> O(1)

    // The main problem here that we needed to solve that are we able to cross zero successfully? If we are able to then that means that 0s have no significance here, we can consider this array without them as we are already able to cross them. If we are not, then that means that we can't reach the last index.
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
