#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int largestRectangleArea1(int n, vector<int>& histo) {
    stack<int> st;
    vector<int> leftSmall(n), rightSmall(n);

    for(int i=0; i<n; i++) {
        while(!st.empty() && histo[st.top()]>=histo[i]) st.pop();

        if(st.empty()) leftSmall[i] = 0;
        else leftSmall[i] = st.top() + 1;
        st.push(i);
    }

    // Clear the stack to be re-used
    while(!st.empty()) st.pop();

    for(int i=n-1; i>=0; i--) {
        while(!st.empty() && histo[st.top()]>=histo[i]) st.pop();

        if(st.empty()) rightSmall[i] = n-1;
        else rightSmall[i] = st.top() - 1;
        st.push(i);
    }

    int maxArea = 0;
    for(int i=0; i<n; i++) {
        maxArea = max(maxArea, (rightSmall[i]-leftSmall[i]+1)*histo[i]);
    }

    return maxArea;

    // TC -> (O(N) + O(N)) + (O(N) + O(N))
    // SC -> O(3N)
}

int largestRectangleArea2(int n, vector<int>& histo) {
    stack<int> st;
    int maxA = 0;

    for(int i=0; i<=n; i++) {
        while(!st.empty() && (i==n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()]; // ith index is used to give the information (height, width) of  the st.top()th index.
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;
            maxA = max(maxA, (height*width));
        }
        st.push(i);
    }

    return maxA;

    // TC -> O(N + N)
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

    int n;
    cin >> n;
    vector<int> histo(n);
    for(int i=0; i<n; i++) cin >> histo[i];

    int maxi1 = largestRectangleArea1(n,histo);
    cout << maxi1 << endl;

    int maxi2 = largestRectangleArea2(n,histo);
    cout << maxi2 << endl;

// Actual Problem:
    vector<vector<int>> mat;
    int n1,n2;
    cin >> n1 >> n2;
    for(int i=0; i<n1; i++) {
        vector<int> arr(n2);
        for(int j=0; j<n2; j++) cin >> arr[j];
        mat.push_back(arr);
    }

    vector<int> temp(n2);
    int maxArea = 0;
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            if(mat[i][j]==0) temp[j] = 0;
            else temp[j]++;
        }
        maxArea = max(maxArea,largestRectangleArea2(n2,temp));
    }

    cout << maxArea << endl;

    return 0;
}
