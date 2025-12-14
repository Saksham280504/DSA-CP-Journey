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

    // Here we start with BST!!
    // BST differs from the BT as the on the left side of the root, every node is smaller than the root. (L<N)
    // In right side, every node is greater than root. (N<R)
    // Overall (L<N<R)
    // Also both the left and right subtree of the root are BSTs aswell.

    // If incase duplicates are there, then we use: L<=N<R

    // BSTs have height log2N, thus the  TC of traversal becomes O(log2N)

    return 0;
}
