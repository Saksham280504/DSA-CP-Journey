#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    bool isPrime(int val) {
        if(val<2) return false;
        if(val==2 || val==3) return true;
        if(val%2==0 || val%3==0) return false;
        for(int i=5; i*i<=val; i+=6) {
            if(val%i==0 || val%(i+2)==0) return false;
        }
        return true;
    }
public:
    int primePalindrome(int n) {
        if(n>=8 && n<=11) return 11;
        for(int i=0; i<=1e5; i++) {
            string s = to_string(i);
            string r = s;
            r.pop_back();
            reverse(r.begin(),r.end());
            int pal = stoi(s+r);
            if(pal >=n && isPrime(pal)) return pal;
        }
        return -1;
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
