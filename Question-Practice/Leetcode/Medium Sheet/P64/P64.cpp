#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// My solution -> back-tracking
class Solution {
    private:
    void solve(int ind, int n, int k, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if(curr.size()==k) {
            ans.push_back(curr);
            return;
        }
        for(int i=ind; i<n; i++) {
            curr.push_back(nums[i]);
            solve(i+1,n,k,nums,curr,ans);
            curr.pop_back();
        }
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int k=0; k<=n; k++) {
            vector<int> curr;
            solve(0,n,k,nums,curr,ans);
        }

        return ans;
    }

    // There is one problem with my solution and it is the outer loop, I am running the recursion everytime for a new k and then storing only those subsets whose size is equal to k, thus I am performing the recursion n+1 times instead of just 1.

    // TC -> O(n*2^n)
};

class Solution {
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int subsets = 1<<n; // For an array of n unique integers, total number of subsets = 2^n (or 1<<n)

        for(int num=0; num<subsets; num++) { // Here, I have created bitmasks, each representing a subset 
            vector<int> sub;
            for(int i=0; i<n; i++) {
                if(num&(1<<i)) sub.push_back(nums[i]); // Every ith set bit of the bitmask tells us to take the ith element into combination
            }
            ans.push_back(sub);
        }

        return ans;

        // TC -> O(N*2^N)


        // For eg:- nums=[1,2,3] => n = 3 => subsets = 2^3 = 8
        // num  binary subset
        // 0     000     []
        // 1     001     [1]
        // 2     010     [2]
        // 3     011     [1,2]
        // 4     100     [3]
        // 5     101     [1,3]
        // 6     110     [2,3]
        // 7     111     [1,2,3]
    }
};


// Optimal solution -> back-tracking
class Solution {
    private:
    void solve(int ind, int n, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);
        for(int i=ind; i<n; i++) {
            curr.push_back(nums[i]);
            solve(i+1,n,nums,curr,ans);
            curr.pop_back();
        }
    }
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,n,nums,curr,ans);
        return ans;
    }

    // TC -> O(2^N)
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
