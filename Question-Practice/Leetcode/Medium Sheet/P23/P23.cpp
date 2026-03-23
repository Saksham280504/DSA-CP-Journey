#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int cnt = 0;
    void backTrack(int pos, int n, vector<bool>& used) {
        if(pos>n) {
            cnt++;
            return;
        }

        for(int num=1; num<=n; num++) {
            if(!used[num] && (pos%num==0 || num%pos==0)) {
                used[num] = true;
                backTrack(pos+1,n,used);
                used[num] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> used(n+1,false);
        backTrack(1,n,used);
        return cnt;
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
