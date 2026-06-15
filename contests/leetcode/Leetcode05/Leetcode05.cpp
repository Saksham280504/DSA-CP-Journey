#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    bool checkGoodInteger(int n) {
        int diff = 0;
        while(n>0) {
            int digit = n%10;
            diff += digit*(digit-1);
            n = n/10;
        }
        return diff>=50;
    }
};

// Q2
class Solution {
public:
    int getLength(vector<int>& arr) {
        int n = arr.size();
        int maxBalancedArrSize = 1;
        for(int i=0; i<n; i++) {
            int maxFreq = 0;
            unordered_map<int,int> mpp;
            for(int j=i; j<n; j++) {
                mpp[arr[j]]++;
                maxFreq = max(maxFreq,mpp[arr[j]]);
                bool isBalanced = (maxFreq%2==0);
                int cnt = 0;
                if(isBalanced) {
                    for(auto it: mpp) {
                        if(it.second==maxFreq) {
                            cnt++;
                            continue;
                        }
                        if(it.second==(maxFreq/2)) continue;
                        isBalanced = false;
                    }
                    if(cnt>1 && cnt==mpp.size()) isBalanced = false;
                }
                if(isBalanced) maxBalancedArrSize = max(maxBalancedArrSize,j-i+1);
            }
        }
        return maxBalancedArrSize;
    }
};

// Q3
class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units[0].size();
        long long ans = 0;
        if(m==1) { // No of units in each device = 1, so the maximum sum of ratings = sum of ratings of each device
            for(auto it: units) {
                ans += it[0];
            }
            return ans;
        }

        long long min_first_unit = LLONG_MAX, sum = 0, min_second_unit = LLONG_MAX;
        int n = units.size();
        for(int i=0; i<n; i++) {
            sort(units[i].begin(), units[i].end());
            sum += units[i][1];
            min_first_unit = min(min_first_unit,1LL*units[i][0]);
            min_second_unit = min(min_second_unit,1LL*units[i][1]);
        }

        ans = sum - min_second_unit + min_first_unit;
        return ans;
    }
};

//Q4

class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        // If number of negative numbers are <= k, then we can accumulate all non-negative numbers together to form the largest sum subarray.
        int negs = 0;
        for(int i: nums) if(i<0) negs++;

        if(negs<=k && negs<n) { 
            long long sum = 0;
            for(int i: nums) if(i>=0) sum = (sum + 1LL*i);
            return sum;
        }

        if(negs==n) { // If negs==n, then all the elements within the array are negative, thus our answer will be the largest element withtin the array
            return *max_element(nums.begin(),nums.end());
        }

        // If k==0, then no swaps are possible, so we use Kadane's algorithm
        if(k==0) {
            long long sum = 0, maxi = LLONG_MIN;
            for(int i: nums) {
                sum = (sum + 1LL*i);
                maxi = max(maxi,sum);
                if(sum<0) sum = 0;
            }
            return maxi;
        }

        vector<vector<long long>> SubArraySum(n,vector<long long>(n));
        vector<vector<long long>> arr1(n,vector<long long>(n)); // arr1[i][j] -> sum of top (or least) k -ve elements in the subarray [i.....j]
        vector<vector<long long>> arr2(n,vector<long long>(n)); // arr2[i][j] -> sum of top k +ve elements outside the subarray [i....j]
        // Now it is possible that the -ve elements in arr1 or +ve elements in arr2 are not exactly k but less than k, that is also not an issue, because our main aim is to get the maximum subArray sum for which keeping the subarray size [i....j] fixed is not necessary. We can increase or decrease the size as per our swapping needs and can get the maximum sum possible.

        for(int i=0; i<n; i++) {
            long long sum = 0;
            for(int j=i; j<n; j++) {
                sum = (sum + 1LL*nums[j]);
                SubArraySum[i][j] = sum;
            }
        }
        for(int i=0; i<n; i++) {
            long long sum = 0;
            priority_queue<int> pq; // This will be used to give the sum of top (or least) k -ve elements in the subarray [i....j]
            for(int j=i; j<n; j++) {
                if(nums[j]<0) {
                    if(pq.size()<k) {
                        pq.push(nums[j]);
                        sum = (sum + 1LL*nums[j]);
                    }
                    else { // pq.size()==k 
                        if(pq.top()>nums[j]) {
                            sum = (sum - 1LL*pq.top());
                            pq.pop();
                            sum = (sum + 1LL*nums[j]);
                            pq.push(nums[j]);
                        }
                    }
                }
                arr1[i][j] = sum;
            }
        }
        for(int i=0; i<n; i++) {
            priority_queue<int,vector<int>,greater<int>> pq; // This will make the pq.top() the smallest element in the priority_queue
            long long sum = 0;
            for(int j=0; j<i; j++) {
                if(nums[j]>0) {
                    if(pq.size()<k) {
                        pq.push(nums[j]);
                        sum = (sum + 1LL*nums[j]);
                    }
                    else {
                        if(pq.top()<nums[j]) {
                            sum = (sum - 1LL*pq.top());
                            pq.pop();
                            pq.push(nums[j]);
                            sum = (sum + 1LL*nums[j]);
                        }
                    }
                }
            }
            arr2[i][n-1] = sum;

            for(int j=n-1; j>i; j--) {
                if(nums[j]>0) {
                    if(pq.size()<k) {
                        pq.push(nums[j]);
                        sum = (sum + 1LL*nums[j]);
                    }
                    else {
                        if(pq.top()<nums[j]) {
                            sum = (sum-1LL*pq.top());
                            pq.pop();
                            sum = (sum+1LL*nums[j]);
                            pq.push(nums[j]);
                        }
                    }
                }
                arr2[i][j-1] = sum;
            }
        }

        long long maxSubArraySum = LLONG_MIN;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                maxSubArraySum = max(maxSubArraySum,SubArraySum[i][j]-arr1[i][j]+arr2[i][j]);
            }
        }
        return maxSubArraySum;
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
