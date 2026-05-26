#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// The core idea of the problem is to use a two-pass greedy approach.
// First step is to store the last Occurance of all the characters ('a' to 'z')
// Second step is to again traverse the array with 2 pointers start and end. Now for every i, update end = max(end,lastOccur[s[i]-'a'])
// If for any i, we have i==end, that means we have successfully certain characters of string in one partition, store its size as (end-start+1), and then do start = i+1, to start the new partition.
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccur(26,-1);
        int n = s.size();
        for(int i=0; i<n; i++) {
            lastOccur[s[i]-'a'] = i;
        }

        vector<int> sizes;
        int start = 0, end = 0;

        for(int i=0; i<n; i++) {
            end = max(end,lastOccur[s[i]-'a']);
            if(i==end) {
                sizes.push_back(end-start+1);
                start = i+1;
            }
        }
        return sizes;
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
