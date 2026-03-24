#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int cnt1 = 0, cnt2=0, sum1=0, sum2=0;
        for(int i=0; i<n; i++) {
            if(i<n/2) {
                if(num[i]=='?')cnt1++;
                else sum1 += num[i]-'0';
            }
            else {
                if(num[i]=='?')cnt2++;
                else sum2 += num[i]-'0';
            }
        }

        if(2*(sum1-sum2)==9*(cnt2-cnt1)) return false; // Bob wins
        return true; // Alice wins

        // If cnt2-cnt1 is odd, then bob will never win.
        // The core idea is to make the left sum and right sum by filling the '?' with integers. Every pair of '?' will cancel out each other. In case any side has more question marks, then each of that question mark will contribute a factor of 9/2 (4.5) and then can see if the sum will become equal or not.
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
