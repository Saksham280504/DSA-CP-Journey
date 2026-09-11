#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int total = 10; // base case for n=1
        int unique = 9; // Number of choices left for leading position for n=2 (1......9) (0 can't be in leading position)
        int available = 9; // Number of choices left in the next position after lead for n=2 (0.....9 / leading position digit)
        for(int i=2; i<=n; i++) {
            unique *= available;
            total += unique;
            available--;
        }
        return total;
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
