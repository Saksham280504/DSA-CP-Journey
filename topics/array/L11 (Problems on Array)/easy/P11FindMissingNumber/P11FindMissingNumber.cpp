#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int MissingNumber(vector<int>& arr, int n) {

    // Brute-force method
    // for(int i=1; i<=n; i++) {
    //     int flag = 0;
    //     for(int j=0; j<n-1; j++) {
    //         if(arr[j] == i) {
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag==0) return i;
    // }

    // TC -> O(N*N) This is too much
    // SC -> O(1)

    // Better-approach

    // int HashArr[n+1] = {0};

    // for(int i=0; i<n-1; i++) {
    //     HashArr[arr[i]] = 1;
    // }

    // for(int i=1; i<n+1; i++){
    //     if(HashArr[i]==0) return i;
    // }
    // TC -> O(2*N)
    // SC -> O(N)

    // Optimal approach -1

    // int sum1 = (n*(n+1))/2;
    // int sum2=0;
    // for(int i=0; i<n-1;i++){
    //     sum2 = sum2+arr[i];
    // }
    // return sum1-sum2;
    // TC -> O(N)
    // SC -> O(1)

    // Optimal approach -2
    
    int XOR1 = 0;
    int XOR2 = 0;
    for(int i=0; i<n-1; i++) {
        XOR2 = XOR2^arr[i];
        XOR1= XOR1^(i+2);
    }
    XOR1 = XOR1^1;
    return XOR1^XOR2;
    // TC->O(N)
    // SC->O(1)

    // The XOR approach is better because if n is large i.e. around 10^5, then XOR approach is much better than SUM.
}
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

    for(int i=0; i<n-1; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    int MissingNum = MissingNumber(arr,n);

    cout << "Missing Number: " << MissingNum << endl;

    return 0;
}
