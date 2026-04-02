#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// You don't need to sort the array, you just need a O(1) HashLookup (unordered_set)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0 ;
        for(int num : st) {
            if(st.find(num-1)==st.end()) {
                int curr = num;
                int len = 1;
                while(st.find(curr+1)!=st.end()) {
                    curr++;
                    len++;
                }

                longest = max(longest,len);
            }
        }

        return longest;
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
