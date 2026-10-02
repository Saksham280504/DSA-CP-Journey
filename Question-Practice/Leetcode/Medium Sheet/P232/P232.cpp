#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    bool subsequenceExists(string& s, string &p, vector<int>& removable, int k) {
        int n = s.size();
        vector<bool> removed(n,false);
        for(int i=0; i<k; i++) {
            removed[removable[i]] = true;
        }
        int i = 0, j=0;
        int m = p.size();
        while(i<n && j<m) {
            if(!removed[i] && s[i]==p[j]) j++;
            i++;
        }
        return j==m;
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0, high = removable.size();
        int ans = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(subsequenceExists(s,p,removable,mid)) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
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
