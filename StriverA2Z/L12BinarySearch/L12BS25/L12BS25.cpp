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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matArr;
    for(int i=0; i<n; i++) {
        vector<int> arr(m);
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        matArr.push_back(arr);
        arr.clear();
    }
    int k;
    cin >> k;

    // Search in a 2D Matrix

    // Brute-force method

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         if(matArr[i][j]==k) {
    //             cout << "YES" << endl;
    //             return 0;
    //         }
    //     }
    // }

    // cout << "NO" << endl;

    // TC -> O(n*m)
    // SC -> O(1)

    // Better Approach

    // for(int i=0; i<n; i++) {
    //     if(matArr[i][0] > k) {
    //         cout << "NO" << endl;
    //         return 0;
    //     }
    //     if(matArr[i][m-1] < k) continue;
    //     int low = 0;
    //     int high = m-1;
    //     while(low<=high) {
    //         int mid = (low+high)/2;
    //         if(matArr[i][mid]<k) low = mid+1;
    //         else if(matArr[i][mid]==k) {
    //             cout << "YES" << endl;
    //             return 0;
    //         }
    //         else high = mid-1;
    //     }
    // }
    
    // cout << "NO" << endl;

    // TC -> O(N) + O(log2(M))
    // SC -> O(1)

    // Optimal Approach

    int low = 0;
    int high = (n*m)-1;

    while(low<=high) {
        int mid = (low+high)/2;
        int row = mid/m;
        int col = mid%m;
        if(matArr[row][col]<k) low  = mid+1;
        else if(matArr[row][col]>k) high = mid-1;
        else {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    // TC -> O(log2(n*m))
    // SC -> O(1)
    
    return 0;
}
