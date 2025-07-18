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

    int t;
    cin >> t;

    vector<int> arr;

    for(int i=0; i<t; i++) {
        int x;
        cin >> x;
        if(x==0) {
            cout << x << endl;
            continue;
        }
        else if(x < 0) x = x*-1;
        int mini = INT_MAX;
        while(x > 0) {
            int y = x%10;
            x = x/10;
            if(y<=mini) mini = y;
        }
        cout << mini << endl;
    }

    return 0;
}
