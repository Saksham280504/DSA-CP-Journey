#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> parent;
vector<int> Rank;
vector<int> len;
int ComponentCount, maxSize;

int find(int x) {
    if(x!=parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    int lx = find(x);
    int ly = find(y);
    if(lx!=ly) {
        if(Rank[lx]>Rank[ly]) {
            parent[ly] = lx;
            len[lx] += len[ly];
        }
        else if(Rank[ly]>Rank[lx]) {
            parent[lx] = ly;
            len[ly] += len[lx];
        }
        else { // Rank[lx]==Rank[ly]
            parent[lx] = ly;
            Rank[ly]++;
            len[ly] += len[lx];
        }
        ComponentCount--;
        maxSize = max(maxSize,max(len[ly],len[lx]));
    }
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
    int n,m;
    cin >> n >> m;
    parent.resize(n+1);
    for(int i=1; i<=n; i++) parent[i] = i;
    Rank.assign(n+1,1);
    len.assign(n+1,1);
    ComponentCount = n;
    maxSize = 1;
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        merge(u,v);
        cout << ComponentCount << " " << maxSize << endl;
    }

    return 0;
}
