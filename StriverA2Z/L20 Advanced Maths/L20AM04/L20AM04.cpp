#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Print prime factors of n

class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> ans;
        for(int i=2; i*i<=n; i++) {
            if(n%i==0) {
                ans.push_back(i);
                while(n%i==0) n=n/i;
            }
        }
        if(n!=1) ans.push_back(n);
        return ans;
    }

    // TC -> O(sqr(N)*logN)
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
