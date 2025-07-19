#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int FindSquareRoot(int n) {
    int low = 1;
    int high = n;
    int ans = INT_MIN;
    while(low<=high) {
        int mid = (low+high)/2;
        if(mid*mid==n) return mid;
        else if(mid*mid<n) {
            ans = max(ans, mid);
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }

    return ans;
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

    // Finding Square Root of a number

    // Easy way is using sqrt function

    // int sqroot;
    // sqroot = sqrt(n);
    // cout << sqroot << endl;

    // Other naive wat is to use Linear search

    // int i = 1;
    // while(i*i <= n) {
    //     i++;
    // }

    // if(i*i==n) cout << i << endl;
    // if(i*i > n) cout << i-1 << endl;

    // Now we will use Binary Search

    int sqroot = FindSquareRoot(n);

    cout << sqroot << endl;
    return 0;
}
