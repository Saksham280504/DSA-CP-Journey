#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int lisBest(int n, vector<int>& arr) {
    vector<int> temp;
    temp.push_back(arr[0]); // LIS will atleast be of size 1
    int length = 1;
    for(int i=1; i<n; i++) {
        if(arr[i]>temp.back()) {
            temp.push_back(arr[i]);
            length++;
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return length;

    // TC -> O(NlogN)
    // SC -> O(LIS)
    // Temp is not the LIS, it is just of the same size as that of the LIS.
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

    // As we see that even by using space-optimization technique, we were getting a TLE because TC was O(N*N)
    // Hence, now we use binary search to get us the answer which will give us the TC of O(NlogN)
    // Binary-Search method here can only be used for getting the size of the LIS, we can't use it for printing the LIS.

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int length = lisBest(n,arr);
    cout << length << endl;

    return 0;
}
