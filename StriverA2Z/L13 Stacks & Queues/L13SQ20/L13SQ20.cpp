#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
    private:
    int maxRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int m = heights.size();
        for(int i=0; i<m; i++) {
            while(!st.empty() && heights[st.top()]>heights[i]) {
                int elIndex = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea,(nse-pse-1)*heights[elIndex]);
            }
            st.push(i);
        }
        while(!st.empty()) { // For these bars we were unable to determine the nse
                int elIndex = st.top();
                st.pop();
                int nse = m;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea,(nse-pse-1)*heights[elIndex]);
        }

        return maxArea;
    }
    public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp(m,0);
        int maxArea = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]=='0') temp[j] = 0;
                else temp[j]+=1;
            }
            maxArea = max(maxArea,maxRectangleArea(temp));
        }
        return maxArea;
    }

    // TC -> O(N*(M+2M))
    // SC -> O(2M)
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
