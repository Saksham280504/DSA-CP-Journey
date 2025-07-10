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
    for(int i=0; i<n;i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    int counter = 0;
    int maxCounter = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]==1) {
            counter=counter+1;
        }
        else {
            if(counter > maxCounter) {
                maxCounter = counter;
            }
            counter = 0;
        }
    }

    cout << "Maximum Consecutive Ones are: " << maxCounter << endl;

    // TC-> O(N)
    // SC -> O(1)
    return 0;
}
