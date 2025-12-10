#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void IsTwoSumPossible(vector<int>& arr,int n, int k) {
    // brute-force method (My-approach / Striver's approach)
    // for(int i=0; i<n; i++) {
    //     for(int j=i+1; j<n; j++) {
    //         if(arr[i] + arr[j] == k) {
    //             cout << "YES and the numbers are: " << i << j << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << "NO THE NUMBERS DON'T EXIST" << endl;

    // TC-> not exactly equal to  O(N*N) but close to it.

    // Better - approach (Hashing)
    
//     map<int, int> mpp;
    
//     for(int i=0; i<n; i++) {
//         int rem = k - arr[i];
//         if(mpp.find(rem) != mpp.end()) {
//             cout << "YES" << endl;
//             cout << mpp[rem] << " and " << i << endl;
//             return;
//         }
//         mpp[arr[i]] = i;
//     }
//     cout << "NO" << endl;

// TC-> O(NlogN) (ordered map) 
// For unorderedMap, we have worst case: O(N*N)
// --> Best & average case: O(N)
// SC -> O(N)

// Optimal solution (only for variety 1 question (YES/NO only))

sort(arr.begin(), arr.end());
int left = 0;
int right = n-1;

while(left < right) {
    if(arr[left] + arr[right] < k) left++;
    else if(arr[left] + arr[right] > k) right--;
    else {
        cout << "YES";
        return;
    }
    
}
cout << "NO";
return;
}

// TC O(N) + O(NlogN)
// SC O(1)

// This is only optimised for YES/NO variety. IF you try to get indices then, for that you would need to store the array in a different data structure first and then apply the sort. But THAT WILL NOT BE AN OPTIMAL SOLUTION THEN.

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
    for(int i=0; i<n; i++ ) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }
    int k;
    cin >> k;
    IsTwoSumPossible(arr, n, k);
    return 0;
}
