#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// At max only 2 elements can become majority elements here.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = 0, cnt1 = 0, candidate2 = 0, cnt2 = 0;
        for(int x: nums) {
            if(x==candidate1 && cnt1>0) cnt1++;
            else if(x==candidate2 && cnt2>0) cnt2++;
            else if(cnt1==0) {
                candidate1 = x;
                cnt1 = 1;
            }
            else if(cnt2==0) {
                candidate2 = x;
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
                // Occurance of 3 distinct elements cancels out.
                // Majority element will never get cancelled out.
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        int limit = n/3;
        for(int x: nums) {
            if(x==candidate1) cnt1++;
            else if(x==candidate2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>limit) ans.push_back(candidate1);
        if(cnt2>limit) ans.push_back(candidate2);
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
