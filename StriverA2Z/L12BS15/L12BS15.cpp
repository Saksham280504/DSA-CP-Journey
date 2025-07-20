#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool isShipPossible(vector<int>& arr, int n, int days, int capacity) {
    int sum = 0;
    int day = 1;
    for(int i=0; i<n; i++) {
        sum+=arr[i];
        if(sum<=capacity) continue;
        else {
            day++;
            sum = arr[i];
        }
    }
    if(day<=days) return true;
    return false;
}
int LeastCapacity(vector<int>& arr, int n, int start, int last,int days) {
    for(int i=start; i<=last; i++) {
        if(isShipPossible(arr,n,days,i)) return i;
    }
    return -1;
}

int LeastCapacityBS(vector<int>& arr, int n, int start, int last, int days) {
    int low = start;
    int high = last;
    while(low<=high) {
        int mid = (low+high)/2;
        if(isShipPossible(arr,n,days,mid)) high = mid-1;
        else low = mid+1;
    }
    return low;
}

// Not possible pointer (low) ends as possible pointer, whereas possible pointer(high) ends at low. This is the concept of opposite polarity.

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
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int days;
    cin >> days;

    // int start = INT_MIN;
    // int last = 0;

    // for(int i=0; i<n; i++) {
    //     start = max(start, arr[i]);
    //     last += arr[i];
    // }

    // You can find start and last by either using the above method or by using c++ STL.

    int start = *max_element(arr.begin(), arr.end());
    int last = accumulate(arr.begin(), arr.end(), 0);

    // int minCapacity = LeastCapacity(arr,n,start,last,days);
    // TC -> O((last-start+1)*N) This can be optimised using Binary Search

    int minCapacity = LeastCapacityBS(arr,n,start,last,days);
    // TC -> O(log2(last-start+1)*N)

    if(minCapacity==-1) cout << "Ship not possible" << endl;
    else cout << minCapacity << endl;

    return 0;
}
