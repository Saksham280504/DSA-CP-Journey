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

    // Solution - 1
    // int x;
    // cin >> x;
    // if(x<3 || x>18) cout << "No" << endl;
    // else cout << "Yes" << endl;

    // Solution - 2
    // vector<vector<double>> presence(3,vector<double>(3,0));
    // for(int i=0; i<3; i++) {
    //     for(int j=0; j<6; j++) {
    //         int x;
    //         cin >> x;
    //         if(x==4) presence[i][0]++;
    //         else if(x==5) presence[i][1]++;
    //         else if(x==6) presence[i][2]++;
    //     }
    // } 

    // double prob = 0;
    // for(int i=0; i<3; i++) {
    //     double temp = presence[0][i]/6.0;
    //     for(int j=0; j<3; j++) {
    //         if(i==j) continue;
    //         double temp1 = presence[1][j]/6.0;
    //         for(int k=0; k<3; k++) {
    //             if(k==j || k==i) continue;
    //             double temp2 = presence[2][k]/6.0;
    //             double temp3 = temp;
    //             temp = temp*temp1;
    //             temp = temp*temp2;
    //             prob += temp;
    //             temp = temp3;
    //         }
    //     }
    // }
    // cout << prob << endl;

    
    return 0;
}
