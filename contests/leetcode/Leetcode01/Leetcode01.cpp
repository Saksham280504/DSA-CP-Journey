#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(auto x: nums) mpp[x]++;
        vector<int> ans;
        for(auto it: mpp) {
            int freq = min(it.second,k);
            while(freq--) ans.push_back(it.first);
        }
        return ans;
    }
};

// Q2
class Solution {
public:
    int passwordStrength(string str) {
        unordered_map<char,int> mpp;
        int points = 0;
        for(char x: str) {
            mpp[x]++;
        }
        for(auto it: mpp) {
            if('a'<= it.first && it.first<='z') points += 1;
            else if('A'<=it.first && it.first<='Z') points += 2;
            else if('0'<=it.first && it.first<='9') points += 3;
            else if(it.first=='!' || it.first=='@' || it.first =='#' || it.first=='$') points += 5;
        }

        return points;
    }
};

// Q3 (My Solution) -> HardCoded
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int position = -1;
        for(int i=1; i<n-1; i++) {
            if(nums[i]==0) position = i;
            int diff1 = abs(nums[i]-nums[i-1]);
            int diff2 = abs(nums[i]-nums[i+1]);
            if(diff1==1 && diff2==1) continue;
            else if(diff1==n-1 && diff2==1) continue;
            else if(diff2==n-1 && diff1==1) continue;
            else return -1;
        }
        if(position==-1) {
            if(nums[0]==0) position = 0;
            else if(nums[n-1]==0) position = n-1;
        }
        if(position<n-1 && nums[position+1]==1) return min(position,2+n-position);
        if(position<n-1 && nums[position+1]==n-1) return min(position+2,n-position);
        if(position==n-1 && nums[position-1]==1) return 1;
        return min(n-1,3);
    }
};

// Q4 

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
