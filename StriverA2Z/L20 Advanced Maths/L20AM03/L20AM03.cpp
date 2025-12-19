#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Check if prime

class Solution {
  public:
    bool isPrime(int n) {
        int cnt = 0;
        for(int i=1; i*i<=n; i++) {
            if(n%i==0) {
                cnt++;
                if((n/i)!=i) cnt++;
            }
            if(cnt>2) break;
        }
        if(cnt==2) return true;
        return false;
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
