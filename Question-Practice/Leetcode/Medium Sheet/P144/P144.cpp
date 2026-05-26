#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_sum = 0;
        for(int num: nums) xor_sum ^= num;
        long long smallest_set_bit = (xor_sum & -xor_sum); // Since xor_sum = A^B where A and B are the two unique elements of the array with single occurance. This approach will give us the smallest set bit at which A and B differ. We can then divide all the elements of the array into two groups (group1 which have that bit set and group2 which don't). From here, we get the final result as group1 = A and group2 = B finally as the remaining elements occur in pairs and will become 0 on using XOR.
        long long group1 = 0;
        long long group2 = 0;
        for(int num: nums) {
            if(num & smallest_set_bit) {
                group1 ^= num;
            }
            else group2 ^= num;
        }
        return {(int)group1, (int)group2};
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
