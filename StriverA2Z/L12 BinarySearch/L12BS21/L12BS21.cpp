#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numberOfGasStationsRequired(long double dist, vector<int>& arr, int n) {
    int cnt = 0;
    for(int i=1; i<n; i++) {
        int numberInBetween = ((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])/dist == numberInBetween*dist) numberInBetween--;

        cnt += numberInBetween;
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

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    // Minimise Maximum Distance between Gas Stations

    // brute-force solution

    // vector<int> HowMany(n-1, 0);
    // The index of section = The index of Initial element of the section in the array.

    // for(int i=0; i<k; i++) {
    //     long double maxSection = -1;
    //     int maxInd = -1;
    //     for(int j=0; j<n-1; j++) {
    //         long double diff = arr[j+1] - arr[j];
    //         long double sectionLength = diff/ (long double) (HowMany[j]+1); // Here we are basically trying to find the sectionLength of each interval(arr[i],arr[i+1])
    //         if(sectionLength > maxSection) {
    //             maxSection = sectionLength;
    //             maxInd = j;
    //         }
    //     }
    //     HowMany[maxInd]++;
    // }

    // for(int i=0; i<n-1; i++) {
    //     cout << HowMany[i] << " ";
    // }
    // cout << endl;

    // long double maxAns = -1;
    // for(int i=0; i<n-1; i++) {
    //     long double diff = arr[i+1] - arr[i];
    //     long double  sectionLength = diff/(long double) (HowMany[i]+1);
    //     maxAns = max(maxAns, sectionLength);
    // }

    // cout << maxAns << endl;

    // TC -> O(k*n +n)

    // Better Approach (Priority_queue -> Heap Structure)

    // vector<int> HowMany(n-1,0);

    // priority_queue<pair<long double,int>> pq;

    // for(int i=0; i<n-1; i++) {
    //     pq.push({arr[i+1]-arr[i], i});
    // }

    // for(int gasStation = 1; gasStation<=k; gasStation++) {
    //     auto tp = pq.top(); // This will give you the maximum sectionLength
    //     pq.pop();
    //     int secInd = tp.second;
    //     HowMany[secInd]++;
    //     long double IniDiff = arr[secInd+1]-arr[secInd];
    //     long double newSecLen = IniDiff/(long double) (HowMany[secInd]+1);
    //     pq.push({newSecLen, secInd});        
    // }

    // cout << pq.top().first << endl;

    // TC -> O(NlogN + klogN)
    // SC -> O(N-1)

    // Optimal Approach (BS on double)

    long double low = 0;
    long double high = 0;

    for(int i=0; i<n-1; i++) {
        high = max(high, (long double) (arr[i+1]-arr[i]));
    }

    long double diff = 1e-6;
    while(high - low > diff) {
        long double mid = (low+high)/(2.0);
        int cnt = numberOfGasStationsRequired(mid, arr,n);
        if(cnt > k) low = mid;
        else high = mid;
    }

    cout << high << endl;

    // TC -> O(nlogn + n)
    // SC -> O(1)

    return 0;
}
