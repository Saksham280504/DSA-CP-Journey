#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

string debruijn(int k, int n) {
    string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(k<=0 || n<=0 || k>alphabet.size()) return "";

    int numNodes = 1;
    for(int i=0; i<n-1; i++) {
        numNodes *= k;
    } // numNodes = k^(n-1)

    vector<int> nextEdge(numNodes,0); // For every node i.e. k^(n-1) string we have k digits (0...k-1) to append. Once nextDigit[v]
    vector<pair<int,int>> Stack;
    Stack.push_back({0,-1});

    vector<int> cycleDigits;

    while(!Stack.empty()) {
        int u = Stack.back().first;
        if(nextEdge[u]<k) {
            int d = nextEdge[u]++;
            int v = (u*k+d)%numNodes;
            Stack.push_back({v,d});
        }
        else {
            auto p = Stack.back();
            Stack.pop_back();
            int d = p.second;
            if(d!=-1) cycleDigits.push_back(d);
        }
    }

    reverse(cycleDigits.begin(), cycleDigits.end());
    string result;
    for(int i=0; i<n-1; i++) {
        result.push_back(alphabet[0]);
    }
    for(int d: cycleDigits) {
        result.push_back(alphabet[d]);
    }
    return result;
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

    int k,n;
    cin >> n;
    k= 2;

    string s = debruijn(k,n);

    cout << s << endl;

    return 0;
}
