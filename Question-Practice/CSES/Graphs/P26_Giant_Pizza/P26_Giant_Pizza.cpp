#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int n,m;
vector<vector<int>> adjLS, adjLSRev;
vector<bool> vis, assigned;
stack<int> finishingOrder;
vector<int> component;

int negateVar(int x) {
    return x<=m ? x+m : x-m;
}

void addClause(int x, int y) {
    adjLS[negateVar(x)].push_back(y);
    adjLS[negateVar(y)].push_back(x);
    adjLSRev[y].push_back(negateVar(x));
    adjLSRev[x].push_back(negateVar(y));
}

void dfsOriginal(int node) {
    vis[node] = true;
    for(int adj: adjLS[node]) {
        if(!vis[adj]) dfsOriginal(adj);
    }
    finishingOrder.push(node);
}

void dfsReverse(int node, int comp) {
    component[node] = comp;
    for(int adj: adjLSRev[node]) {
        if(!component[adj]) dfsReverse(adj,comp);
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
    cin >> n >> m;
    // n -> number of family members
    // m -> number of topings
    adjLS.resize(2*m+1);
    adjLSRev.resize(2*m+1);
    for(int i=0; i<n; i++) {
        string sign1, sign2;
        int x,y;
        cin >> sign1 >> x >> sign2 >> y;
        if(sign1=="-") x = negateVar(x);
        if(sign2=="-") y = negateVar(y);
        addClause(x,y);
    }
    vis.resize(2*m+1);
    for(int i=1; i<=2*m; i++) {
        if(!vis[i]) dfsOriginal(i);
    }

    component.assign(2*m+1,0);
    int comp = 1;
    while(!finishingOrder.empty()) {
        int u = finishingOrder.top();
        finishingOrder.pop();
        if(!component[u]) dfsReverse(u,comp++);
    }

    for(int i=1; i<=m; i++) {
        if(component[i]==component[negateVar(i)]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    assigned.resize(m+1);

    for(int i=1; i<=m; i++) {
        if(component[i]>component[negateVar(i)]) assigned[i] = true;
    }

    for(int i=1; i<=m; i++) {
        cout << (assigned[i] ? "+ " : "- ");
    }
    cout << endl;

    return 0;
}
