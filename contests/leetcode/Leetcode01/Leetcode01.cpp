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
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums2.size();
        int blockSize = max(1,int(sqrt(n)));
        int numBlocks = (n+blockSize-1)/blockSize;

        // SquareRoot Decomposition Structures
        vector<unordered_map<long long,int>> blockMap(numBlocks);
        vector<long long> lazy(numBlocks,0);

        for(int i=0; i<n; i++) {
            int bId = i/blockSize;
            blockMap[bId][nums2[i]]++;
        }

        vector<int> result;

        for(auto q: queries) {
            int type = q[0];
            if(type==1) {
                int x = q[1];
                int y = q[2];
                long long val = q[3]; // This line prevents run time error

                int startBlock = x/blockSize;
                int endBlock = y/blockSize;

                if(startBlock==endBlock) {
                    // Update partially covered single block
                    for(int i=x; i<=y; i++) {
                        blockMap[startBlock][nums2[i]]--;
                        nums2[i] += val;
                        blockMap[startBlock][nums2[i]]++;
                    }
                }
                else {
                    // Updating partial start block
                    int endOfStart = (startBlock+1)*blockSize-1;
                    for(int i=x; i<=endOfStart; i++) {
                        blockMap[startBlock][nums2[i]]--;
                        nums2[i] += val;
                        blockMap[startBlock][nums2[i]]++;
                    }
                    
                    // Updating complete intermediate blocks
                    for(int i=startBlock+1; i<endBlock; i++) {
                        lazy[i] += val;
                    }
            
                    // Updating partial end Block
                    int startOfEnd = (endBlock)*blockSize;
                    for(int i=startOfEnd; i<=y; i++) {
                        blockMap[endBlock][nums2[i]]--;
                        nums2[i] += val;
                        blockMap[endBlock][nums2[i]]++;
                    }
                }
            }
            else {
                long long tot = q[1];
                int totalPairs = 0;
                for(int m: nums1) {
                    long long targetInNums2 = tot - m;
                    for(int b=0; b<numBlocks; b++) {
                        int neededRawValue = targetInNums2-lazy[b];
                        auto it = blockMap[b].find(neededRawValue);
                        if(it!=blockMap[b].end()) {
                            totalPairs += blockMap[b][neededRawValue];
                        }
                    }
                }
                result.push_back(totalPairs);
            }
        }
        return result;
    }
};


// Gemini Chat Link :- https://gemini.google.com/app/b8a6a9626c7ddc2a?is_sa=1&is_sa=1&android-min-version=301356232&ios-min-version=322.0&campaign_id=bkws&pt=9008&mt=8&ct=p-growth-sem-bkws

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
