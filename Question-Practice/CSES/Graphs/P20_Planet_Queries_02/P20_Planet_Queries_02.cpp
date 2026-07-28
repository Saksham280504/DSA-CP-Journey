#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int MAX_HEIGHT = 20;
vector<int> arr;
vector<vector<int>> binaryLifting;
vector<int> len;
vector<bool> visited;

void dfs(int node) {
    if(visited[node]) return;
    visited[node] = true;
    dfs(arr[node]);
    binaryLifting[node][0] = arr[node];
    len[node] = len[arr[node]]+1;
    for(int i=1; i<MAX_HEIGHT; i++) {
        binaryLifting[node][i] = binaryLifting[binaryLifting[node][i-1]][i-1];
    }
}

int jump(int node, int dist) {
    if(dist<0) return -1;
    int curr = node;
    for(int level=0; level<MAX_HEIGHT; level++) {
        if(dist&(1<<level)) {
            curr = binaryLifting[curr][level];
        }
    }
    return curr;
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

    int n,q;
    cin >> n >> q;
    arr.resize(n+1);
    binaryLifting.assign(n+1,vector<int>(MAX_HEIGHT));
    len.assign(n+1,0);
    visited.assign(n+1,false);

    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    for(int i=1; i<=n; i++) {
        if(!visited[i]) dfs(i);
    }

    while(q--) {
        int a,b;
        cin >> a >> b;
        int cycle_entry_a = jump(a,len[a]);
        if(jump(a,len[a]-len[b])==b) {
            cout << len[a]-len[b] << endl;
        }
        else if(jump(cycle_entry_a,len[cycle_entry_a]-len[b])==b) {
            cout << len[cycle_entry_a]-len[b]+len[a] << endl;
        }
        else cout << -1 << endl;
    }

    return 0;
}
