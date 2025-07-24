#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int rowOfMax(vector<vector<int>>& matArr, int n, int mid) {
    int maxi = INT_MIN;
    int ind = -1;
    for(int i=0; i<n; i++) {
        if(matArr[i][mid] >= maxi) {
            maxi = matArr[i][mid];
            ind = i;
        }
    }
    return ind;
}

vector<int> PeakElement(vector<vector<int>>& MatArr, int n, int m) {
    int low = 0;
    int high = m-1;
    while(low<=high) {
        int mid = (low+high)/2;
        int row = rowOfMax(MatArr,n,mid);
        int left = mid-1>=0 ?  MatArr[row][mid-1] : -1;
        int right = mid+1<n  ? MatArr[row][mid+1] : -1;
        if(MatArr[row][mid] > left && MatArr[row][mid]> right) return {row,mid};
        else if(MatArr[row][mid] < left) high = mid-1;
        else low = mid+1;
    }
    return {-1,-1};
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
    vector<vector<int>> MatArr;
    for(int i=0; i<n; i++) {
        vector<int> arr(m);
        for(int j=0; j<m; j++) {
            cin >> arr[j];
        }
        MatArr.push_back(arr);
    }

    // Find Peak Element

    // Brute-force method -> Scan through very element and look for the largest element and that will give us the peak element with TC -> O(n*m) for the best, average and worst case

    // Better Approach
    vector<int> PeakCoord = PeakElement(MatArr, n , m);
    
    // TC -> O((log2(m)*n))
    // SC -> O(1)

    for(int i=0; i<2; i++) {
        cout << PeakCoord[i] << " ";
    }
    return 0;
}
