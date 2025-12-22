#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    string removeKdigits(string num, int k) {
        list<char> ls;
        int n = num.size();
        for(int i=0; i<n; i++) {
            while(!ls.empty() && k>0 && ((ls.back()-'0'))>(num[i]-'0')) {
                ls.pop_back();
                k--;
            }
            ls.push_back(num[i]);
        }
        // 1st edge case (k>0) (elements were in ascending order)
        while(k>0) {
            ls.pop_back();
            k--;
        }
        if(ls.size()==0) return "0"; // 3rd edge case (if after all the removals, the list is empty then we return "0")

        // 2nd edge case (00100) (remove the starting zeros)
        while(!ls.empty() && ls.front()=='0') {
            ls.pop_front();
        }
        if(ls.size()==0) return "0"; // 3rd edge case (if after all the removals, the list is empty then we return "0")

        string res = "";
        while(!ls.empty()) {
            res += ls.front();
            ls.pop_front();
        }
        return res;

        // TC -> O(N(creation of ls) + k () + N(removing the zeroes and emptying the ls into res))
        // SC -> O(2N)
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
