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
