#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void markRow(int i,vector<vector<int>>& arr, int m) {
    for(int j=0; j<m; j++) {
        if(arr[i][j]!=0) arr[i][j] = -1;
    }
}

void markCol(int j,vector<vector<int>>& arr, int n) {
    for(int i=0; i<n; i++) {
        if(arr[i][j]!=0) arr[i][j] = -1;
    }
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

    // int n,m;
    // cin >> n >> m;
    // int arr[100][100];

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cin >> arr[i][j];
    //     }
    // }

    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr; // This is the way to call out a matrix.
    vector<int> rowArr;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++ ){
            int nums;
            cin >> nums;
            rowArr.push_back(nums);
        }
        arr.push_back(rowArr);
        rowArr.clear();
    }

    // Brute-force method

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(arr[i][j]==0) {
    //             markRow(i, arr, m);
    //             markCol(j, arr, n);
    //         }
    //     }
    // }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(arr[i][j]==-1) arr[i][j]=0;
    //     }
    // }

    // TC -> O((n*m)*(n+m) + (n*m))

    // Better Approach

    // int col[m] = {0};
    // int row[n] = {0};

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(arr[i][j]==0) {
    //             col[j] = 1;
    //             row[i] = 1;
    //         }
    //     }
    // }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(col[j]==1 || row[i]==1) {
    //             arr[i][j] = 0;
    //         }
    //     }
    // }

    // TC -> O(2*N*M)
    // SC -> O(N+M)

    // Optimal Approach

    int col0 = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]==0) {
                arr[i][0]=0;
                if(j!=0) {
                arr[0][j]=0;
                } else {
                col0 = 0;
                }
            }
        }
    }

    for(int i=n-1; i>=1; i--) {
        for(int j=m-1; j>=1; j--) {
            if(arr[0][j]==0 || arr[i][0]==0) {
                arr[i][j]=0;
            }
        }
    }

    for(int j=m-1; j>=1; j--) {
        if(arr[0][0]==0) {
            arr[0][j] = 0;
        }
    }

    for(int i=n-1; i>=0; i--) {
        if(col0 == 0) {
            arr[i][0] = 0;
        }
    }

    // TC -> O(2*N*M)
    // SC -> O(1)

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
