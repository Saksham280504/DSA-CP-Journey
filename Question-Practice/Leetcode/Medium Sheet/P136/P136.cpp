#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// At max only 2 elements can become majority elements here.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;

        for(int x: nums) {
            if(x==candidate1) count1++;
            else if(x==candidate2) count2++;
            else if(count1==0) {
                candidate1 = x;
                count1 = 1;
            }
            else if(count2==0) {
                candidate2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
                // One occurrence of three different numbers cancels out.
                // A true majority element (>n/3) can never be cancelled.
            }
        }

        // We need to verify, even if an element is a potential candidate, it doesn't prove him to be the majority element.
        count1 = 0;
        count2 = 0;
        int limit = n/3;
        vector<int> ans;

        for(int x: nums) {
            if(x==candidate1) count1++;
            if(x==candidate2) count2++;
        }

        if(count1>limit) ans.push_back(candidate1);
        if(count2>limit) ans.push_back(candidate2);

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
