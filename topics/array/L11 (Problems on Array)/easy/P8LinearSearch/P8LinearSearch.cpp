#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int LinearSearch(vector<int>& arr, int number) {
    for(int i=0; i<arr.size();i++) {
        if(arr[i]==number) {
            return i;
        }
    }
    return -1;
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

    vector<int> arr;

    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    int number;
    cin >> number;

    int index = LinearSearch(arr,number);

    if(index==-1) {
        cout << "THE NUMBER IS NOT PRESENT IN THE ARRAY" << endl;
        return 0;
    }

    cout << "The number exists at index: " << index << endl;
    return 0;
}
