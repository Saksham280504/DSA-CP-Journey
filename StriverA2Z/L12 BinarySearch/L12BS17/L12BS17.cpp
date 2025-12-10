#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
bool isCowsPossible(vector<int>& stalls, int n, int diff, int cows) {
    int CowCnt = 1;
    int last = stalls[0];
    for(int i=1; i<n; i++) {
        if((stalls[i]-last)>=diff) {
            CowCnt++;
            last = stalls[i];
        }
        if(CowCnt>=cows) return true;
    }
    return false;
}
int maxOfMin(vector<int>& stalls, int n, int cows) {
    for(int diff=1; diff<=stalls[n-1]-stalls[0]; diff++) {
        if(isCowsPossible(stalls, n, diff, cows)) continue;
        else return diff-1;
    }

    return -1;
}

int maxOfMinBS(vector<int>& stalls, int n, int cows) {
    int low = 1;
    int high = stalls[n-1]-stalls[0];
    while(low<=high) {
        int mid = (low+high)/2;
        if(isCowsPossible(stalls, n, mid, cows)) low = mid+1;
        else high = mid-1;
    }
    return high;
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
    vector<int> stalls(n);

    for(int i=0; i<n; i++) {
        cin >> stalls[i];
    }

    int cows;
    cin >> cows;

    // Find the maximum of minimum distance possible between cows.

    // So we know that for minimum distance between the cows, we need only the consecutive distance.

    // Firstly, we will sort the positions of the stalls given in the stall array.

    sort(stalls.begin(), stalls.end());
    
    // Linear method approach

    // int maxDiff = maxOfMin(stalls,n,cows);
    // TC -> O(NlogN + (stalls[max]-stalls[min)*N) This can be optimised using binary search.

    int maxDiff = maxOfMinBS(stalls,n,cows);

    if(maxDiff==-1) cout << "No minimum difference possible" << endl;
    else cout << maxDiff << endl;

    return 0;
}
