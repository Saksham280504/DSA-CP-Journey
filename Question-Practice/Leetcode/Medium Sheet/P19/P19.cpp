#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Uncommon subsequence is that string which is a subsequence of one string but not of other.
// The key idea of the problem is to find the longest string which is not a subsequence of any other string in the array. We don't need to generate the subsequences but just need to check which is the longest string in the array that is not a subsequence of any other string.
class Solution {
    private:
    bool static comp(string &a, string &b) {
        return a.size() > b.size();
    }

    bool isSubsequence(string& a, string& b) {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        while(i<n && j<m) {
            if(a[i]==b[j]) i++;
            j++;
        }

        return (i==n);
    }
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), comp);

        for(int i=0; i<n; i++) {
            bool uncommon = true;
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                if(isSubsequence(strs[i], strs[j])) {
                    uncommon = false;
                    break;
                }
            }
            if(uncommon) return strs[i].size();
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
