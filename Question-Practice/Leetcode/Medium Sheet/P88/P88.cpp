#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    bool static comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp); // We sort the pairs as per the smallest ends first rule. This gives us the maximum chance to form the largest chain.
        // A normal sort will not work because it will prioritize left[i] more than right[i] for sorting, which will make it difficult for us to choose which pair should be a part of the chain and which one should not be a part of the chain.
        int cnt = 0;
        int lastEnd = INT_MIN;
        for(auto pair: pairs) {
            if(pair[0]>lastEnd) {
                cnt++;
                lastEnd = pair[1];
            }
        }
        return cnt;

        // TC -> O(NlogN)
        // SC -> O(1)
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
