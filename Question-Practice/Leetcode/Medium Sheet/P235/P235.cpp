#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        int n = s.size();
        for(int i=n-1; i>0; i--) {
            int val = (s[i]-'0') + carry;
            if(val==1) { // Odd -> 2 steps -> (add 1 to make 2, change it to 0 and a create a carry of 1) + then divide by 2 
                carry = 1;
                steps += 2;
            }
            else { // val = 0 or val = 2 -> only division is needed
                steps += 1;
            }
        }
        // The 0th bit will always be 1 initially as it is promised in the question
        return steps + carry; // if carry = 1, then 1+1 = 2 (divide by 2 -> 1 step), if carry = 0 then 1 + 0 = 1 (no more steps)
    }
};

// s -> 1110101
// steps = 0, carry = 0
// i = 6 -> val = 1 + 0 = 1 -> 1 will be added and then division by 2 -> steps = 2, carry = 1
// i = 5 -> val = 0 + 1 = 1 -> steps = 4, carry = 1
// i = 4 -> val = 1 + 1 = 2 -> steps = 5 (just divide)
// i = 3 -> val = 0 + 1 = 1 -> steps = 7
// i = 2 -> val = 1 + 1 = 2 -> steps = 8
// i = 1 -> val = 1 + 1 = 2 -> steps = 9
// i = 0 -> return 9 + 1 = 10 steps

// Now s = 1110101 ->  1*2^6 + 1*2^5 + 1*2^4 + 0*2^3 + 1*2^2 + 0*2^1 + 1*2^0 = 64 + 32 + 16 + 0 + 4 + 1 = 117
// 6th bit
// n = 117 -> step - 1 -> n++ => n = 118
// n = 118 -> step - 2 -> n/2 => n = 59
// 5th bit
// n = 59 -> step - 3 -> n++ => n = 60
// n = 60 -> step - 4 -> n/2 => n = 30
// 4th bit
// n = 30 -> step - 5 -> n/2 => n = 15
// 3rd bit
// n = 15 -> step - 6 -> n++ => n = 16
// n = 16 -> step - 7 -> n/2 => n = 8
// 2nd bit
// n = 8 -> step - 8 -> n/2 => n = 4
// 1st bit
// n = 4 -> step - 9 -> n/2 => n = 2
// 0th bit
// n = 2 -> step - 10 -> n/2 => n = 1 

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
