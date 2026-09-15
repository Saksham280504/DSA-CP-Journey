#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

#define ll long long
class Solution {
private:
    vector<int> nseCompute(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n,n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nse[i] = (st.empty() ? n: st.top()); 
            st.push(i);
        }
        return nse;
    }
    vector<int> pseeCompute(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n,-1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            psee[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = nseCompute(arr);
        vector<int> psee = pseeCompute(arr);
        ll total = 0;
        ll mod = 1e9+7;
        for(int i=0; i<n; i++) {
            ll left = i-psee[i];
            ll right = nse[i]-i;
            total = (total + right*left*arr[i])%mod;
        }
        return total;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
