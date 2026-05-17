#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// int numOfSusequences(int ind, int sum, vector<int>& arr) {
//     if(ind<0) return 0;
//     int notTake = numOfSusequences(ind-1,sum,arr);
//     int take = numOfSusequences(ind-1,sum+arr[ind],arr);
//     if((sum + arr[ind])%3==0) take = max(take,1 + numOfSusequences(ind-1,0,arr));
//     return max(notTake,take);
// }
// void solve1() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++) cin >> arr[i];
//     int maxi = numOfSusequences(n-1,0,arr);
//     cout << maxi << endl;
// }

// The main problem with the above solution is that the question was about maximizing the number of operations and not building subsequences. Because after finding a valid subsequence you are also removing the subsequence but the above code doesn't simulate that function properly. 

// Also, if we observe clearly we will see that the above problem can be solved using greedy approach. Since w has only 0,1,2 as its elements, there are only 4 ways possible for the sum to become divisible by 3. 1. [0] -> 0, 2. [1,2] -> 3, 3. [1,1,1] -> 3, 4. [2,2,2] -> 6
// So our way of approach will be to first find all the zeroes and consider each zero as a valid subsequence. Secondly, find as many pairs of (1,2) as possible. Then the remaining 1s will build 3 and remaining 2s will build 6.

void solve1() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int c0 = 0, c1 = 0, c2 = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i]==0) c0++;
        else if(arr[i]==1) c1++;
        else c2++;
    }
    int ans = c0;
    int pairs = min(c1,c2);
    c1 -= pairs;
    c1 /=3;
    c2 -= pairs;
    c2 /=3;
    ans += (pairs+c1+c2);
    cout << ans << endl;
}

void solve2() {
    int n,x1,x2,k;
    cin >> n >> x1 >> x2 >> k;
    if(n==2 || n==2) {
        cout << 1 << endl;
        return;
    }
    int d = abs(x1-x2);
    d = min(d,n-d);
    cout << k + d << endl;
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
