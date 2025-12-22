#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private: 
vector<int> Findnse(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n,n);
    stack<int> st;
    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
vector<int> Findpsee(vector<int>& arr) {
    int n = arr.size();
    vector<int> psee(n,-1);
    stack<int> st;
    for(int i=0; i<n; i++) {
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = Findnse(arr);
        vector<int> psee = Findpsee(arr);
        int total = 0;
        int mod = (int)(1e9+7);
        int n = arr.size();
        for(int i=0; i<n; i++) {
            int right = nse[i]-i;
            int left = i-psee[i];
            total = (total + (right*1LL*left*arr[i])%(mod))%mod;
        }
        return total;

        // TC -> O(5N)
        // SC -> O(4N)
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
