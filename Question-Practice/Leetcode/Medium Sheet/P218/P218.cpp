#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

#define ll long long
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        vector<ll> freq(101,0);
        for(int x: arr) {
            freq[x]++;
        }
        ll ways = 0;
        ll mod = 1e9+7;
        for(int x=0; x<=100; x++) {
            if(!freq[x]) continue;
            for(int y=x; y<=100; y++) {
                if(!freq[y]) continue;
                int z = target-y-x;
                if(z>100 || z<y || !freq[z]) continue;
                if(x==y && y==z) ways += (freq[x]*(freq[x]-1)*(freq[x]-2))/6; // freq[x]C3
                else if(x==y && y<z) ways += ((freq[x]*(freq[x]-1))/2)*freq[z]; // (freq[x]C2)*(freq[z]C1)
                else if(x<y && y==z) ways += freq[x]*((freq[y]*(freq[y]-1))/2); // (freq[x]C1)*(freq[y]C2)
                else { // x<y<z (freq[x]C1)*(freq[y]C1)(freq[z]C1)
                    ways += freq[x]*freq[y]*freq[z];
                }
                ways %= mod;
            }
        }
        return ways;
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
