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
    int n,m;
    cin >> n >> m;
    unordered_map<int,int> pos;
    pos[0] = 0;
    pos[n+1] = n+1;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for(int i=2; i<=n; i++) {
        if(pos[i]<pos[i-1]) rounds++;
    }

    // Increment or decrement of rounds totally depends upon the adjacent neighbours (x+1,x-1) of x. If they lie within the range of swap. Then rounds get changed.
    while(m--) {
        int i,j;
        cin >> i >> j;
        if(i>j) swap(i,j); // i<j
        int x = arr[i], y = arr[j];
        if(pos[x+1]>i && pos[x+1]<j) rounds++;
        if(pos[x-1]>i && pos[x-1]<j) rounds--;
        if(pos[y+1]>i && pos[y+1]<j) rounds--;
        if(pos[y-1]>i && pos[y-1]<j) rounds++;
        if(y==(x+1)) rounds++;
        if(y==(x-1)) rounds--;

        cout << rounds << endl;
        swap(arr[i],arr[j]);
        pos[x] = j;
        pos[y] = i;
    }

    return 0;
}
