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

    // This is a greedy Algorithm lecture, where we are given two arrays of n children and m cookies, the children array contains the minimum size of the cookie needed to satisfy a child and the cookie array contains the size of cookies.

    int n,m;
    cin >> n >> m;
    vector<int> children(n), cookies(m);

    for(int i=0; i<n; i++) cin >> children[i];
    for(int i=0; i<m; i++) cin >> cookies[i];

    // Step-1: Sort both the arrays
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    // Step-2: Assign a left and right pointer

    int left = 0; // For cookie size
    int right = 0; // For child size

    while(left<m && right<n) {
        if(cookies[left]>=children[right]) right++;
        left++;
    }   

    cout << right << endl; 

    // TC -> O(N*M + NLogN + MLogM)
    // SC -> O(1)

    // Here we have greedily tried to assign the smallest values possible of the cookies so that maximum number of children can be satisfied.
    return 0;
}
