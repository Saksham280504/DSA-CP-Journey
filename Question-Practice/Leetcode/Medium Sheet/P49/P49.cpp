#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// My solution -> O(N)
class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        int cnt = 0;
        for(char c: s) {
            if(c=='[') open++;
            else if(open==0) cnt++;
            else open--;
        }
        cnt += open;
        return cnt%4==0 ? cnt/4: cnt/4+1;
        // Intuition -> Every time we swap the left-most unbalanced ] bracket with the rightmost [ bracket, we resolve atmost 2 pairs.
        // ][ -> cnt=2 -> on 1 swap we get [] (1 pair resolved)
        // ]][[ -> cnt=4 -> on 1 swap we get [][] (2 pair resolved)
        // ]]][[[ -> cnt=6 -> on 1 swap we get []][[] (2 pair resolved) -> one 1 more swap, we get [][][] (3 pair resolved)

        // Also ]][[ can also be written as A]B]C[D[E, where A,B,C,D,E are all balanced substrings
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
