#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int findRow(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int ans = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(matrix[mid][0]==target) return mid;
            if(matrix[mid][0]<target) {
                ans = mid;
                low = mid+1;
            }
            else { // matrix[mid][0]>target
                high = mid-1;
            }
        }
        return ans;    
    }

    bool isElementThere(vector<int>& row, int target) {
        int low = 0;
        int high = row.size()-1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(row[mid]==target) return true;
            if(row[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix,target); // TC -> O(logN)
        if(row==-1) return false;
        return isElementThere(matrix[row],target); // TC -> O(logM)
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
