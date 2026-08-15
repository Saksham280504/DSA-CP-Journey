#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<pair<int,int>> moves;

void hanoi(int n, int from, int to, int aux) {
    if(n==0) return;
    hanoi(n-1,from,aux,to);
    moves.push_back({from,to});
    hanoi(n-1,aux,to,from);
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
    hanoi(n,1,3,2);

    cout << moves.size() << endl;
    for(auto it: moves) {
        cout << it.first << " " << it.second;
        cout << endl;
    }


    return 0;
}
