#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Print all divisors

class Solution {
  public:
    void print_divisors(int n) {
        vector<int> ans;
        for(int i=1; i*i<=n; i++) {
            if(n%i==0) {
                ans.push_back(i);
                if(n/i!=i) ans.push_back(n/i);
            }
        }

        sort(ans.begin(),ans.end());

        for(auto x: ans) cout << x << " ";
    }

    // TC -> O(sqr(N))
    // SC -> Depends on N
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
