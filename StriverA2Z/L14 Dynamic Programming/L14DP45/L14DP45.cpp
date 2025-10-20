#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

bool compare(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    if(n!=m+1) return false;
    int first=0;
    int second=0;

    while(first<n) {
        if(s1[first]==s2[second]) {
            first++;
            second++;
        }
        else first++;
    }

    if(first==n && second==m) return true;
    return false;
}

bool comp(string & s1, string& s2) {
    return s1.size() < s2.size();
}

int lsc(int n, vector<string>& arr) {
    
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n,1);
    int maxi = 1;

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(compare(arr[i],arr[j]) && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        }
        maxi = max(maxi,dp[i]);
    }

    return maxi;

    // TC -> O(NlogN) (sort) + (O(N*N*Length of String s1))
    // SC -> O(N)
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

    // You are given an array of strings and you have to written the longest string chain possible in that array of strings.

    int n;
    cin >> n;
    vector<string> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int maxLength = lsc(n,arr);
    cout << maxLength << endl;

    return 0;
}
