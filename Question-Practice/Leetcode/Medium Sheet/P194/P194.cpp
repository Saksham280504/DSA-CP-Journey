#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
        // Try to understand it like this:- 
        // Alice at first had choices for taking elements from both even index or odd index. So If Alice wants to always win and if she knows which parity elements will have greater sum, won't it become certain for her to win always.
        // For eg:- 
        // arr = [3,5,7,8] -> Even index elements sum = 10 , odd index elements sum = 13 -> Even Sum + Odd Sum = Total Sum = 23 (odd)
        // Now since Alice already know that odd index elements sum > even index elements sum, she will try to choose only odd index elements because she can!!
        // [3,5,7,8] -> Alice = 0, Bob = 0 (Alice get to choose from both indices of both parity)
        // [3,5,7] -> Alice = 8, Bob = 0 (Note that bob only have even indices to choose from)
        // [3,5] -> Alice = 8, Bob = 7 (Alice again have choice to chose from even or odd index)
        // [3] -> Alice = 13, Bob = 7 (Bob only have even index)
        // [] -> Alice = 13, Bob = 10 (Alice Wins!!!)
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
