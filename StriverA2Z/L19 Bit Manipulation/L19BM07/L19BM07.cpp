#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    int func1(int N) {
        if(N%4==1) return 1;
        else if(N%4==2) return N+1;
        else if(N%4==3) return 0;
        else return N;
    }
  public:
    int findXOR(int l, int r) {
        return func1(l-1) ^ func1(r);
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
