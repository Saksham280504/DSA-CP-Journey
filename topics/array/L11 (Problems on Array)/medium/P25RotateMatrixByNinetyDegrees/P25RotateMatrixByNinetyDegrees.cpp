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
    vector<vector<int>> arr;
    vector<int>rowArr;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int nums;
            cin >> nums;
            rowArr.push_back(nums);
        }
        arr.push_back(rowArr);
        rowArr.clear();
    }

    // Brute-force approach

    // vector<vector<int>> ansArr;
    // vector<int> ansRow;
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         ansRow.push_back(0);
    //     }
    //     ansArr.push_back(ansRow);
    //     ansRow.clear();
    // }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         ansArr[j][n-i-1] = arr[i][j];
    //     }
    // }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout << ansArr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // TC -> O(N*N)
    // SC -> O(N*N)

    // Optimal-approach

    // 1. Transposing the matrix

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
     
    // TC -> O(N*N/2)

    // 2. Reversing the rows

    for(int i=0; i<n; i++) {
        reverse(arr[i].begin(), arr[i].end()); // Every row of the matrix is a vector<int> itself.
    }

    // TC -> O(N*N/2)

    // In total, TC -> O(N*N)
    // SC -> O(1)

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
