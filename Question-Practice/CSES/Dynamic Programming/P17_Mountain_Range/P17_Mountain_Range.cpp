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

    // your code here
    int n;
    cin >> n;
    vector<pair<int,int>> height(n);
    for(int i=0; i<n; i++) {
        cin >> height[i].first;
        height[i].second = i;
    }
    vector<int> nge(n), pge(n);
    stack<int> st;
    for(int i=0; i<n; i++) {
        while(!st.empty() && height[st.top()].first<=height[i].first) st.pop();
        if(st.empty()) pge[i] = -1;
        else pge[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && height[st.top()].first<=height[i].first) st.pop();
        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();
        st.push(i);
    }

    // We see that dp[idx] is dependent on dp[ngeIdx] and dp[pgeIdx], so that means that before computing dp[idx] we must have already computed dp[i] for all i where height[i].first > height[idx].first, that's why we sort
    sort(height.rbegin(), height.rend());
    vector<int> dp(n);
    // dp[i] -> max mountains in a valid route whose final mountain is i.
    for(int i=0; i<n; i++) {
        int idx = height[i].second; // This is the actual index of the mountain, and all nge, pge, and dp will use this idx only.
        int ngeIdx = nge[idx];
        int pgeIdx = pge[idx];
        dp[idx] = 1; // You visit only one mountain if you start from and end at the same mountain.
        if(ngeIdx!=-1) dp[idx] = max(dp[idx],dp[ngeIdx]+1);
        if(pgeIdx!=-1) dp[idx] = max(dp[idx],dp[pgeIdx]+1);
    }
    int ans = *max_element(dp.begin(),dp.end());
    cout << ans << endl;

    return 0;
}
