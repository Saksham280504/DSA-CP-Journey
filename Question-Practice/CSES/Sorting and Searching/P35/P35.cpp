#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

ll solve_using_multiset(vector<ll>& arr, int n, int a, int b) {
    multiset<ll> wnd; // This multiset will act as a window
    vector<ll> preSum(n+1,0LL);
    ll ans = LLONG_MIN;
    for(int i=1; i<=n; i++) {
        preSum[i] = preSum[i-1] + arr[i-1];
        if(i<a) continue; // The window size is not capable of making a subarray ending at index i of length 'a' as of now, so increase the window size.
        wnd.insert(preSum[i-a]); // At an index i, we want to see the maximum subarray sum that we can generate from all the subarrays ending at index i with length of subarray lying in the interval [a,b]. So for making a subarray ending at index i with length = len, we need prefixSum[i]-prefixSum[i-len]
        if(i>b) wnd.erase(wnd.find(preSum[i-b-1])); // We want the window to only hold the values from prefixSum[i-a] to prefixSum[i-b]
        ll maxSubarraySum = preSum[i]-(*wnd.begin());
        ans = max(ans,maxSubarraySum);
    }
    return ans;
}

ll solve_using_deque(vector<ll>& arr, int n, int a, int b) {
    deque<ll> wnd;
    vector<ll> preSum(n+1,0LL);
    ll ans = LLONG_MIN;
    for(int i=1; i<=n; i++) {
        preSum[i] = preSum[i-1]+arr[i-1];
        if(i<a) continue;
        while(!wnd.empty() && wnd.back()>preSum[i-a]) wnd.pop_back(); // All the prefixSums in the window which are bigger than the current entering prefixSum will never be coming on wnd.front() thus should never be considered.
        wnd.push_back(preSum[i-a]);
        if(i>b) if(wnd.front()==preSum[i-b-1]) wnd.pop_front();
        ll maxSubArraySum = preSum[i] - wnd.front();
        ans = max(ans,maxSubArraySum);
    }
    return ans;
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

    int n,a,b;
    cin >> n >> a >> b;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    // ll ans = solve_using_multiset(arr,n,a,b);
    ll ans = solve_using_deque(arr,n,a,b);
    cout << ans << endl;

    return 0;
}
