#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ansArr;
        int left=0, right=n-1, top=0, bottom=m-1;
        while(left<=right && top<=bottom) {
            for(int i=left; i<=right; i++) ansArr.push_back(matrix[top][i]);
            top++;
            for(int i=top; i<=bottom; i++) ansArr.push_back(matrix[i][right]);
            right--;
            if(top<=bottom) {
                for(int i=right; i>=left; i--) ansArr.push_back(matrix[bottom][i]);
                bottom--;
            }
            if(left<=right) {
                for(int i=bottom; i>=top; i--) ansArr.push_back(matrix[i][left]);
                left++;
            }
        }

        return ansArr;
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
