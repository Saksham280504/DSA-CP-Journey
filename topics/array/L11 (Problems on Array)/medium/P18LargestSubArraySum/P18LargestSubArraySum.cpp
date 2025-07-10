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

    // brute-force approach

    // int maxi = INT_MIN;
    // for (int i=0; i<n; i++) {
    //     for (int j=i; j<n; j++) {
    //         int sum = 0;
    //         for(int k=i; k<=j; k++) {
    //             sum += arr[k];
    //             maxi = max(maxi, sum);
    //         }
    //     }
    // }

    // TC -> O(N*N*N) (near-about)
    // SC-> O(1)

    // Better-approach

    // int maxi = INT_MIN;
    // for(int i=0; i<n; i++) {
    //     int sum=0;
    //     for(int j=i; j<n; j++) {
    //         sum += arr[j];
    //         maxi = max(maxi, sum);
    //     }
    // }

    // TC -> O(N*N) (near-about)
    // SC -< O(1)

    // Optima-solution

    // int maxi = INT_MIN;
    // int sum=0;
    // for(int i=0; i<n; i++) {
    //     sum += arr[i];
    //     maxi = max (maxi,sum);
    //     if(sum < 0) sum=0;
    // }

    // if(maxi > 0) {
    //     cout << "Maximum Sum of Subarray is: " << maxi << endl;
    //     return 0;
    // }

    // cout << "No sub array sum is > 0" << endl;

    // TC -> O(N)
    // SC -> O(1)


    // Optimal solution for printing the subarray with maximum sum

    int maxi = INT_MIN;
    int sum=0;
    int start = 0;
    int StartInd = 0;
    int LastInd = 0;
    for(int i=0; i<n; i++) {
        if(sum==0) start = i;
        sum += arr[i];
        if(sum > maxi) {
            StartInd = start;
            LastInd = i;
            maxi = sum;
        }
        if(sum < 0) sum=0;
    }

    cout << "The sub array with the maximum sum is: " << endl;
    for(int i=StartInd; i<=LastInd; i++) {
        if(i!= LastInd)cout << arr[i] << " + ";
        else cout << arr[i] << " : " << maxi << endl;
    }
    return 0;
}
