#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution { // Maximum size subarray with atmost two types of numbers
public:
    int totalFruit(vector<int>& arr) {
        int maxLen=0, l=0, r=0;
        map<int,int> mpp; // {type,frequency}
        int n = arr.size();
        while(r<n) {
            mpp[arr[r]]++;
            if(mpp.size()>2) {
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                l++;
            }
            if(mpp.size()<=2) maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }

    // TC -> O(N)
    // SC -> O(1)
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
