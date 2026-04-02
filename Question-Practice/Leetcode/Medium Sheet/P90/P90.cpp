#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// ChatGPT Solution -> TC -> O(32N) -> Every bit from 0-> 31 is a unique bit. For all the numbers appearing three times, we will see that these bits will be set in a multiple of 3. When the unique number will appear, it will make certain bits set and thus the number of times these bits are set will now not be a multiple of 3. We want those bits to be included in our result.x
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<32; i++) {
            int cnt = 0;
            for(int num: nums) {
                if(num&(1<<i)) cnt++;;
            }
            if(cnt%3) result |= (1<<i);
        }

        return result;
    }
};

// Striver Solution -> TC -> O(N)
// This solution is way better as it makes the outer loop of checking for every bit one-by-one disappear. Here we check for all bits at once.
// Every bit will have four states of being set -

// Count ones twos
//   0    0    0
//   1    1    0
//   2    0    1
//   3    0    0 (reset)

// So consider an arr = [2,2,2,3,3,3,4] for example. Here we will see the following states of ones and twos as the for loop propogates:-
// Initial state -> ones = 000 and twos = 000
// i=0 => arr[i] = 2 => ones = (000^(010))&(~(000)) -> 010 (2 appeared once, thus it is inserted into ones)
//                      twos = (000^(010))&(~(010)) -> 000 (2 appeared once, thus it is not inserted into twos)                      
// i=1 => arr[i] = 2 => ones = (010^(010))&(~(000)) -> 000 (2 appeared twice, thus it is removed into ones)
//                      twos = (000^(010))&(~(000)) -> 010 (2 appeared twice, thus it is inserted into ones)
// i=2 => arr[i] = 2 => ones = (000^(010))&(~(010)) -> 000 (2 appeared thrice, thus it is not inserted into ones)
//                      twos = (010^(010))&(~(000)) -> 000 (2 appeared thrice, thus it is not only removed from ones, it is being reset which means it is considered to not have appeared once.)
// i=3 => arr[i] = 3 => ones = (000^(011))&(~(000)) -> 011 (3 appeared once, thus it is inserted into ones)
//                      twos = (000^(011))&(~(011)) -> 000 (3 appeared once, thus it is not inserted into twos)                      
// i=4 => arr[i] = 3 => ones = (011^(011))&(~(000)) -> 000 (3 appeared twice, thus it is removed into ones)
//                      twos = (000^(011))&(~(000)) -> 011 (3 appeared twice, thus it is inserted into ones)
// i=5 => arr[i] = 3 => ones = (000^(011))&(~(011)) -> 000 (3 appeared thrice, thus it is not inserted into ones)
//                      twos = (011^(011))&(~(000)) -> 000 (3 appeared thrice, thus it is not only removed from ones, it is being reset which means it is considered to not have appeared once.)
// i=6 => arr[i] = 4 => ones = (000^(100))&(~(000)) -> 100 (4 appeared once, thus it is inserted into ones)

// So, finally we get ones = 4 which is the answer. Now even if the numbers were jumbled, we know that ^ is commutative, thus we will still get the same result.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(auto it: nums) {
            ones = (ones^it)&(~twos);
            twos = (twos^it)&(~ones);
        }
        return ones;
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
