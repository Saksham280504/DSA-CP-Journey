#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int upperBound(vector<vector<int>>& MatArr, int i, int m, int x) {
    int low = 0;
    int high = m-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(MatArr[i][mid]<=x) low = mid+1;
        else high = mid-1;
    }
    return low;
}
int countSmallEquals(vector<vector<int>>& MatArr, int n , int m, int mid) {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        cnt += upperBound(MatArr,i,m,mid);
    }
    return cnt;
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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> MatArr;

    for(int i=0; i<n; i++) {
        vector<int> arr(m);
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        MatArr.push_back(arr);
    }

    // Find median of a row-wise sorted matrix

    // Brute0-force method

    // vector<int> arr1(n*m);

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         arr1[i*m+j]=(MatArr[i][j]);
    //     }
    // }

    // for(int i=0; i<n*m; i++) {
    //     cout << arr1[i] << " ";
    // }

    // cout << endl;

    // sort(arr1.begin(), arr1.end());

    // int num = (n*m);
    // int medInd = num/2;

    // cout << arr1[medInd] << endl;

    // TC -> O((n*m) + (n*m)log2(n*m))
    // SC -> O(1)

    // Optimal solution

    int low = INT_MAX;
    int high = INT_MIN;

    for(int i=0; i<n; i++) {
        low = min(MatArr[i][0],low);
        high = max(MatArr[i][m-1],high);
    }

    int req = (n*m)/2;
    while(low<=high) {
        int mid = (low+high)/2;
        int smallEqual = countSmallEquals(MatArr,n,m,mid);
        if(smallEqual<=req) low = mid+1;
        else high = mid-1;
    }

    cout << low << endl;

    // TC -> O(log2(10^9)*n*log2(m))
    // SC -> O(1)
    return 0;
}
