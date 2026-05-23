#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Solution {
private:
    int searchRow(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size()-1, ans = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(matrix[mid][0]<=target) {
                ans = mid;
                low = mid+1;
            }
            else { // matrix[mid][0] > target
                high = mid-1;
            }
        }
        return ans;
    }

    int searchCol(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix[0].size()-1, ans = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(matrix[0][mid]<=target) {
                ans = mid;
                low = mid+1;
            }
            else { // matrix[0][mid] > target
                high = mid-1;
            }
        }
        return ans;
    }

    bool BinarySearch(vector<int>& arr, int high, int target) {
        int low = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(arr[mid]==target) return true;
            if(arr[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = searchRow(matrix,target);
        int col = searchCol(matrix,target);
        if(row<0 || col<0) return false;
        if(matrix[row][0]==target || matrix[0][col]==target) return true;

        bool isFound = false;
        for(int i=0; i<=row; i++) {
            if(BinarySearch(matrix[i],col,target)) return true;
        }
        return false;
    }

    // This solution takes O(NlogM) time in the worst case. This is not the efficient solution.
};

class Solution {
    public: 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int row = 0, col = matrix[0].size()-1;
        while(row<n && col>=0) {
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) col++;
            else row--;
        }
        return false;
    }

    // TC -> O(N+M)
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
