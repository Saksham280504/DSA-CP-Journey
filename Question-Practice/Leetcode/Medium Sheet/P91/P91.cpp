#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// The main idea of the problem is -> 
// For eg:- if n=12, then the best way to obtain it is by copy-pasting 6 (largest factor), so if I backtrack the journey, then I would have got it like this-
// n = 12 = 6+6 (2 Operations (copy 6 + paste 6) = 12/2)
// Now to get 6, the best way is to copy and paste 3 -> 6 = 3+3 (2 Operations = 6/3)
// Now to get 3, the best way is to copy paste 1 -> 3 = 1+1+1 (3 Operations = 3/1)
class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int i=1; 
        int ans = -1;
        while(i<=n/2) {
            if(n%i==0) ans = i;
            i++;
        }
        return (n/ans) + minSteps(ans);
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
