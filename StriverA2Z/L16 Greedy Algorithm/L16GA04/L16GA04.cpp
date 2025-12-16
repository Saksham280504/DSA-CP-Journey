#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(auto it: bills) {
            if(it==5) five++;
            if(it==10) { // Only one way (10++,5--)
                if(five>0) {
                    ten++;
                    five--;
                }
                else return false;
            }
            if(it==20) { // Two ways possible (20++,10--,5--) or (20++, 5--*3)
                if(ten>0 && five>0) { // We always want to have as many change as we have with us, so spend lesser amount of notes wherever possible
                    twenty++;
                    ten--;
                    five--;
                }
                else if(five>2) { // Worst case
                    twenty++;
                    five -= 3;
                }
                else return false;
            }
        }

        return true;

        // TC -> O(bills.size())
        // SC -> O(1)
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
