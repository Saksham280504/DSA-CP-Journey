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
    long long k;
    cin >> k;

    // Brute-force method (approach-1)
    // int length = 0;
    // for(int i=0; i<n; i++) {
    //     for(int j=i; j<n; j++) {
    //         int sum = 0;
    //         for(int m=i; m<=j; m++) {
    //             sum += arr[m];
    //         }
    //         if(sum==k) {
    //             length = max(length,j-i+1);
    //         }
    //     }
    // }

    // TC-> O(N*N*N)
    // SC-> O(1)
    
    // Brute-force method (approach-2)

    // int length = 0;
    // for(int i=0; i<n; i++) {
    //     int sum=0;
    //     for(int j=i; j<n; j++) {
    //         sum += arr[j];
    //         if(sum==k) {
    //             length = max(length,j-i+1);
    //             break;
    //         }
    //     }
    // }
    // TC-> O(N*N)
    // SC-> O(1)

    // Better-approach

    // long long Prefixsum = 0;
    // int Maxlength = 0;
    // map<long long, int> preSumMap;

    // for(int i=0; i<n; i++) {
    //     Prefixsum += arr[i];
    //     if(Prefixsum == k) {
    //         Maxlength = max(Maxlength,i+1);
    //     }
    //     long long rem = Prefixsum - k;
    //     if(preSumMap.find(rem) != preSumMap.end()){
    //         int len = i - preSumMap[rem];
    //         Maxlength = max(Maxlength, len);
    //     }
    //     if(preSumMap.find(Prefixsum) == preSumMap.end()){
    //         preSumMap[Prefixsum] = i;
    //     }
    // }


    // cout << Maxlength << endl;

    // This code works for all types of integers i.e., positive, negative and zeroes, and if in any question, all three of them are present, then this is the optimal solution there

    // Optimal approach (only when the array contain only positives and zeroes)

    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;

    while(right < n) {
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    return 0;

    // TC-> O(2N) The inner loop need not to run on every iteration of outer loop and that's why the overall time complexity to the worst case becomes O(2N).

    // SC-> O(1)
}
