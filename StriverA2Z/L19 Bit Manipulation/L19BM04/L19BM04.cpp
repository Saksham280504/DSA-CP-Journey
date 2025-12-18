#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start^goal;        
        int cnt = 0;
        if(n==0) return cnt;
        cnt=1;
        while((n&(n-1))>0) {
            cnt++;
            n = n&(n-1);
        }
        return cnt;

        // TC -> O(number of set bits)
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
