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
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    cout << "Array before Left-Rotation: " << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int firstInteger = arr[0];

    for(int i=0; i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1] = firstInteger;

    cout << "Array after Left-Rotation: " << endl;
    // TC -> O(N)
    // SC -> O(1)

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
