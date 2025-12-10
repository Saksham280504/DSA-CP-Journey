#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int nCr(int row, int col) {
    int res =1;
    for(int i=0; i<col; i++) {
        res = res*(row-i);
        res = res/(i+1);
    }
    return res;
}
// TC -> O(col)
// SC -> O(1)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // Type-1 Problem (Print the number at Rth row and Cth column)

    // int r, c;
    // cin >> r >> c;
    // int value;
    // value = nCr(r-1,c-1);

    // cout << value << endl;


    // Type-2 Problem (Print Rth row)

    // Brute-force approach
    // int r;
    // cin >> r;

    // for(int c=1; c<=r; c++) {
    //     int value;
    //     value = nCr(r-1,c-1);
    //     cout << value << " ";
    // }

    // TC -> O(R*C) SC-> O(1)

    // Optimal approach

    // int r;
    // cin >> r;
    // int value = 1;
    // for(int c=0; c<r; c++) {
    //     if(c==0) value = 1;
    //     else {
    //         value = value*(r-c)/c;
    //     }
    //     cout << value << " ";
    // }
    // TC -> O(R) SC-> O(1)

    // Type-3 Problem (Print entire Pascal's Triangle)

    int n;
    cin >> n;

    // brute-force method

    // for(int r=1;r<=n; r++) {
    //     for(int c=1; c<=r; c++) {
    //         int value;
    //         value = nCr(r-1,c-1);
    //         cout << value << " ";
    //     }
    //     cout << endl;
    // }

    // TC -> O(N*N*N) 
    // SC -> O(1)

    // Optimal Approach

    for(int r=1; r<=n; r++) {
        long long value = 1;
        for(int c=0; c<r; c++) {
            if(c==0) cout << value << " ";
            else {
                value = value*(r-c)/c;
                cout << value << " ";
            }
        }
        cout << endl;
    }

    // TC -> O(N*N) SC -> O(1)

    return 0;
}
