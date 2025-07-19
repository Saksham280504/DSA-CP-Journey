#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int maxElement(vector<int>& arr,int n) {
    int maxi=INT_MIN;
    for(int i=0; i<n; i++) {
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

int timeTaken(vector<int>& arr,int n, int k) {
    int TimeTaken = 0;
    for(int i=0; i<n; i++) {
        TimeTaken += ceil((double)arr[i]/(double)k);
    }
    return TimeTaken;
}
int MinimumHourlyRate(vector<int>& arr, int h, int maxi, int n) {
    int hourlyRate = INT_MAX;
    for(int i=1; i<=maxi; i++) {
        int timeRequired = timeTaken(arr,n,i);
        if(timeRequired<=h) hourlyRate = min(hourlyRate,i);
    }

    return hourlyRate;
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
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int h; 
    cin >> h;

    // Brute-force approach

    int maxi = maxElement(arr,n);

    int minRate = MinimumHourlyRate(arr,h,maxi,n);

    cout << minRate << endl;

    return 0;
}
