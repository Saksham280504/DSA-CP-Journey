#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lowerBound(vector<int> arr, int m) {
    int low = 0;
    int high = m-1;
    while(low<=high) {
        int mid = (low + high)/2;
        if(arr[mid]==1) high = mid-1;
        else low = mid+1;
    }

    return low;
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

    int n,m;
    cin >> n >> m;
    vector<vector<int>> matArr;

    for(int i=0; i<n; i++) {
        vector<int> arr(n);
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        matArr.push_back(arr);
        arr.clear();
    }

    // Brute-force method
    // int maxCnt = -1;
    // int rowCnt = -1;
    // for(int i=0; i<n; i++) {
    //     int cnt = 0;
    //     for(int j=0; j<n; j++) {
    //         cnt += matArr[i][j];
    //     }
    //     if(cnt > maxCnt) {
    //         maxCnt = cnt;
    //         rowCnt = i+1;
    //     }
    // }

    // cout << rowCnt << endl;

    // TC -> O(n*m)
    // SC -> O(1)

    // Optimal Approach (lower-bound Concept)

    // LowerBound is the smallest index such that arr[ind] >= x
    
    int rowCnt = -1;
    int maxCnt = -1;
    for(int i=0; i<n; i++) {
        int cnt = m - lowerBound(matArr[i],m);
        if(cnt > maxCnt) {
            maxCnt = cnt;
            rowCnt = i+1;
        }
    }

    cout << rowCnt << endl;

    // TC -> O(N*log(M))
    // SC -> O(1)
    return 0;
}
