#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void solve1() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    int finalPosition = (((n&1) > 0) ? arr[n/2] : (arr[n/2]+arr[(n/2)-1])/2);
    int low = 0, high = n-1;
    int calls = 0;
    while(low<high) {
        if(arr[low]==finalPosition && finalPosition==arr[high]) break;
        calls++;
        low++;
        high--;
    }

    cout << calls << endl;
}

void solve2() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> ans(n,0);
    ans[0] = arr[0];
    long long prevExtra = 0;
    for(int i=1; i<n; i++) {
        if(arr[i]<ans[i-1]) {
            int gap = ans[i-1] - arr[i];
            if(gap>1)ans[i] = arr[i] + gap/2;
            else if(prevExtra>0) { // gap == 1
                ans[i] = ans[i-1];
                prevExtra--;
            }
            else { // prevExtra == 0
                ans[i] = arr[i];
                prevExtra++;
            }
            if(gap&1 && gap>1) prevExtra++;
            if(i>1) prevExtra += (ans[i-1]-ans[i])*(i-1);
        }
        else {  // arr[i]>=ans[i-1]
            ans[i] = ans[i-1];     
            prevExtra += (arr[i]-ans[i-1]);
        }
    }

    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << endl;
}

void solve3() {
    int n,x,s;
    cin >> n >> x >> s;
    string u;
    cin >> u;
    int m = u.size();
    bool isAnyEmptyTableAvailable = true;
    bool isAnyNonEmptyTableAvailable = false;
    int totalSeatsTaken = 0;
    for(int i=0; i<m; i++) {
        if(u[i]=='E' && !isAnyNonEmptyTableAvailable) n--;
        if(u[i]=='I' && !isAnyEmptyTableAvailable) n--;
        if(u[i]=='A') {
            if(i==m-1) {
                if(x==0) n--;
                totalSeatsTaken++;
                if(totalSeatsTaken==s) {
                    isAnyNonEmptyTableAvailable = false;
                    totalSeatsTaken = 0;
                    x--;
                }
                else {
                    
                }
            }
        }
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
    int t;
    cin >> t;
    while(t--) solve2();

    return 0;
}
