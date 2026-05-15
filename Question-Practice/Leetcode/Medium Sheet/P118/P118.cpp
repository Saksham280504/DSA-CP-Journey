#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // The core-concept of this problem is that after all & operations, only those bit of the upcoming number will be set which were set in all the numbers from left to right
        // Therefore to find the solution, we will right shift both left and right until they become equal. This is so because the unmatching suffix will anyhow become zero, all we have eyes on is the matching prefix.
        int shift = 0;
        while(left!=right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
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
