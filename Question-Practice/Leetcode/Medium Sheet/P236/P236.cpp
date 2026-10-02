#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m);
        iota(p.begin(),p.end(),1);
        int n = queries.size();
        vector<int> ans;
        for(int q=0; q<n; q++) {
            int num = queries[q];
            int idx = find(p.begin(),p.end(),num)-p.begin();
            for(int i=idx; i>0; i--) {
                p[i] = p[i-1];
            }
            p[0] = num;
            ans.push_back(idx);
        }
        return ans;
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
