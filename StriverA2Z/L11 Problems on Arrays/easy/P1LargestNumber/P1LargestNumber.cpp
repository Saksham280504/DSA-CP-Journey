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
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    // Brute force method
    // sort(arr.begin(), arr.end());
    // cout << arr[n-1] << endl;
    // This takes the TC of O(NlogN).

    // Optimal method
    int largest = arr[0];
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > largest) largest = arr[i];
    }
    cout << largest << endl;
    // This takes the time complexity of O(N) which is much smalller than O(NlogN).
    return 0;
}
