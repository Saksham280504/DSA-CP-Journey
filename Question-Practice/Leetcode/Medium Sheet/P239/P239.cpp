#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        bool smaller = false;
        int i =0;
        int maxSize = 1;
        for(int j=1; j<n; j++) {
            if(smaller) {
                if(arr[j]>arr[j-1]) i = j-1;
                else if(arr[j]==arr[j-1]) i = j;
                // The above 2 conditions states that the earlier window met its end, start a new window
                else smaller = (!smaller); // arr[j] < arr[j-1] -> So switch 
            }
            else { // greater
                if(arr[j]<arr[j-1]) i = j-1; 
                else if(arr[j]==arr[j-1]) i = j;
                // The above 2 conditions states that the earlier window met its end, start a new window
                else smaller = (!smaller); // arr[j] > arr[j-1] -> So switch
            }
            maxSize = max(maxSize,j-i+1);
        }
        return maxSize;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
