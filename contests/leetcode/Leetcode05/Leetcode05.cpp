#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

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
