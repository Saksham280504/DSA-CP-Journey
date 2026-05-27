#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int max_so_far = 0;
        int chunks = 0;
        for(int i=0; i<n; i++) {
            max_so_far = max(max_so_far,arr[i]);
            if(max_so_far==i) chunks++;
        }
        return chunks;

        // The important thing to note here is that we are dealing with a permutation here, so in order to check whether a chunk is possible at index i is whether the maximum element that we have seen till now is i or not. 
        // The only possible case is that the max_seen_element will be either greater or equal to i.
        // This is so because all the elements in the array are unique and non-negative. So, if at any index i we see that i==max_so_far, that means that all the elements beyond i will be greater than i.
        // So, wherever we see i==max_so_far, we close a chunk there and start a new one from the forward index.
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
