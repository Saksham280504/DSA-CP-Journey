#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// The core-intuition behind the problem is that- 
// 1. Zero resets everything
// 2. Negative sign flips the product
// At every index, we need to track two things- 1. pos (length of the subarray ending here with positive product) 2. neg (length of the subarray ending here with negative product)
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0, res = 0;
        for(int x : nums) {
            if(x==0) {
                pos = 0;
                neg = 0;
            }
            else if(x>0) {
                pos = pos+1;
                neg = neg>0 ? neg+1: 0;
            }
            else { // x<0
                int new_pos = neg>0 ? neg+1: 0;
                int new_neg = pos+1;
                neg = new_neg;
                pos = new_pos;
            }
            res = max(res,pos);
        }
        return res;
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
