#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numOfSusequences(int ind, int sum, vector<int>& arr) {
    if(ind<0) return 0;
    int notTake = numOfSusequences(ind-1,sum,arr);
    int take = numOfSusequences(ind-1,sum+arr[ind],arr);
    if((sum + arr[ind])%3==0) take = max(take,1 + numOfSusequences(ind-1,0,arr));
    return max(notTake,take);
}
void solve1() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int maxi = numOfSusequences(n-1,0,arr);
    cout << maxi << endl;
}

void solve2() {
    int n,x1,x2,k;
    cin >> n >> x1 >> x2 >> k;
    // x2 -> remilla
    // x1 -> reimu
    int diff = x2-1;
    x2 = 1;
    if(diff==x1)  x1= n;
    else if(diff>x1) {
        diff -= x1;
        x1 = n-diff;
    }
    else x1 -= diff;
    // Now remilla is at x2 = 1
    // and reimu is also shifted accordingly

    int totalTime = 0;
    if((x1-1)==(n-x1+1)) totalTime += (k+1+x1-2);
    else totalTime += (k+min((x1-1),(n-x1+1)));
    
    cout << totalTime << endl;
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
