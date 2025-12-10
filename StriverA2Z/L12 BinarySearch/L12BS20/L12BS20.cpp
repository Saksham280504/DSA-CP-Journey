#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int PaintersTaken(vector<int>& arr, int n, int painterHold) {
    int painterCnt = 1;
    int work = 0;
    for(int i=0; i<n; i++) {
        if(work + arr[i] <= painterHold) work += arr[i];
        else {
            painterCnt++;
            work = arr[i];
        }
    }
    return painterCnt;
}
int MinOfMax(vector<int>& arr, int n, int k, int maxi, int sum) {
    if(n < k) return -1;
    for(int i=maxi; i<=sum; i++) {
        if(PaintersTaken(arr,n,i)==k) return i;
    }
    return -1;
}

int MinOfMaxBS(vector<int>& arr, int n, int k, int maxi, int sum) {
    if(n < k) return -1;
    int low = maxi;
    int high = sum;

    while(low<=high) {
        int mid = (low+high)/2;
        if(PaintersTaken(arr,n,mid)>k) low = mid+1;
        else high = mid-1;
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

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    // To distribute n walls with arr[i] units to be painted on ith wall among k painters. The distribution is such that the painter must get contiguous walls to paint, we want the minimum of maximum time taken by the painters to finish the job.

    int maxi = *max_element(arr.begin(),arr.end());
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // Brute-force method

    // int timeCnt = MinOfMax(arr,n,k,maxi,sum);

    int timeCnt = MinOfMaxBS(arr, n, k, maxi, sum);

    cout << timeCnt << endl;

    return 0;
}
