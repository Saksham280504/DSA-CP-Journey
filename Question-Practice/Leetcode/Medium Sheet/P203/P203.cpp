#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0;
        int mask = 0;
        for(int i=30; i>=0; i--) {
            mask |= (1<<i);
            unordered_set<int> prefixes;
            for(int num: nums) {
                prefixes.insert(num&mask);
            }
            int candidate = maxXor | (1<<i);
            for(int p: prefixes) {
                if(prefixes.count(candidate^p)) maxXor = candidate;
            }
        }
        return maxXor;
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
