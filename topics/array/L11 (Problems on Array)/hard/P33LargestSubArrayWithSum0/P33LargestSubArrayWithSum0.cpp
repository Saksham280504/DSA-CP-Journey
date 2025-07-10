#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    //brute-force method

    // int maxi = 0;
    // for(int i=0; i<n; i++) {
    //     for(int j=i; j<n; j++) {
    //         int sum = 0;
    //         int length;
    //         for(int k=i; k<=j; k++) {
    //             sum += arr[k];
    //         }
    //         if(sum==0) {
    //             length = j-i+1;
    //             maxi = max(maxi,length);
    //         }
    //     }
    // }

    // TC -> O(N*N*N) (approx.)
    // SC -> O(1)

    // Better approach

    // int maxi = 0;
    // for(int i=0; i<n; i++) {
    //     int sum = 0;
    //     for(int j=i; j<n; j++) {
    //         int length;
    //         sum += arr[j];
    //         if(sum==0) {
    //             length = j-i+1;
    //             maxi = max(maxi,length);
    //         }
    //     }
    // }
    // TC -> O(N*N)
    // SC -> O(1)

    // Optimal Approach
    
    int maxi = 0;
    map<int,int> mpp;
    int preSum = 0;
    for(int i=0; i<n; i++) {
        preSum += arr[i];
        if(preSum==0) {
            maxi = i+1;
        }
        else {
            if(mpp.find(preSum) != mpp.end()) {
            int length = i-mpp[preSum];
            maxi = max(length, maxi);
            }
            else {
            mpp[preSum] = i;
            }
        }
    }

    // TC->O(NlogN) (for ordered_map)
    // TC-> O(N) (best & average case in unordered_map)
    // TC-> O(N*N) (worst case in unordered_map)

    // SC -> O(N) (worst case)

    cout << maxi << endl;
    return 0;
}
