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
    // Searching the element in an n*m matrix

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(matArr[i][j]==k) {
    //             cout << i << " & " << j << endl;
    //             return 0;
    //         }
    //     }
    // }

    // cout << "NO" << endl;

    // TC -> O(n*m)
    // SC -> O(1)

    // Better Approach

    // for(int i=0; i<n; i++) {
    //     int low = 0, high = m-1;
    //     while(low<=high) {
    //         int mid = (low+high)/2;
    //         if(matArr[i][mid]<k) low = mid+1;
    //         else if(matArr[i][mid]==k) {
    //             cout << i << " & " << mid << endl;
    //             return 0;
    //         }
    //         else high = mid-1;
    //     }
    // }

    // cout << "NO" << endl;

    // TC -> O(n*log(m))
    // SC -> O(1)

    // Optimal Approach

    int row = 0, col = m-1;

    while(row < n && col >= 0) {
        if(matArr[row][col]<k) row++;
        else if(matArr[row][col]==k) {
            cout << row << " & " << col << endl;
        }
        else col--;
    }
    cout << "NO" << endl;

    // TC -> O(n+m)
    // SC -> O(1)
    return 0;
}
