#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    vector<int> Findnse(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> Findnge(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> Findpsee(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> psee(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    vector<int> Findpgee(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pgee(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }
public:
    long long subArrayRanges(vector<int>& arr) {
        vector<int> nse = Findnse(arr);
        vector<int> nge = Findnge(arr);
        vector<int> psee = Findpsee(arr);
        vector<int> pgee = Findpgee(arr);
        int n = arr.size();
        long long largest = 0;
        long long smallest = 0;
        long long total = 0;
        for(int i=0; i<n; i++) {
            long long rightBig = nge[i]-i;
            long long leftBigorEqual = i-pgee[i];
            long long rightSmall = nse[i]-i;
            long long leftSmallorEqual = i-psee[i];
            smallest = smallest + (rightSmall*leftSmallorEqual*((long long)arr[i]));
            largest = largest + (rightBig*leftBigorEqual*((long long)arr[i]));
            total = largest-smallest;
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
