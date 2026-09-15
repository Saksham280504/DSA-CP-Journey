#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, curr;
        for(int x: arr) {
            unordered_set<int> next_curr;
            next_curr.insert(x);
            for(int y: curr) {
                next_curr.insert(y|x);
            }
            curr = move(next_curr);
            res.insert(curr.begin(),curr.end());
        }
        return res.size();
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
