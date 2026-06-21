#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // In this question you will see that arr[i]>=1, this means that as we move from left to right, the sum of subarray always increases. So here to solve this problem, we will use a sliding window approach where we will always add an element into our curr_sum and whenever curr_sum becomes > x, we will remove the elments from the elements until the curr_sum becomes <=x, if curr==x then increment the total (total number of subarrays having sum x) count.

    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int i=0, j=0;
    ll curr_sum=0, total=0;
    while(j<n) {
        curr_sum += arr[j];
        while(curr_sum>x) {
            curr_sum -= arr[i];
            i++;
        }
        if(curr_sum==x) total++;
        j++;
    }
    cout << total << endl;
    
    return 0;
}
