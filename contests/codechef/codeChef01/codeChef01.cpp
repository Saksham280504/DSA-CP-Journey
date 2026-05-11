#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
// int findRequiredRuns(int opponentScore, int currentScore) {
//     // write your code here 
//     return opponentScore-currentScore+1;
// }

// Q2
// class Solution {
// public:
//     bool isBitSet(long long n, int i) {
//         long long x = 1LL<<i;
//         return n&x;
//     }
// };

// Q3
// void makePowerSet(int idx, vector<int>& curr, vector<int>& inputNumbers, vector<vector<int>>& powerSet) {
//     if(idx>=inputNumbers.size()) return;
//     // Take it
//     curr.push_back(inputNumbers[idx]);
//     powerSet.push_back(curr);
//     makePowerSet(idx+1,curr,inputNumbers,powerSet);
//     // Not take it
//     curr.pop_back();
//     makePowerSet(idx+1,curr,inputNumbers,powerSet);
// }
// vector<vector<int>> findSubsets(vector<int>& inputNumbers) {
//     // write your code here 
//     vector<vector<int>> powerSet;
//     vector<int> curr = {};
//     powerSet.push_back(curr);
//     makePowerSet(0,curr,inputNumbers,powerSet);
//     return powerSet;
// }

// Q4
// void findLargestOddSubstring(string nums) {
//     string ans = "";
//     for(int i=nums.size()-1; i>=0; i--) {
//         int val = nums[i]-'0';
//         if(val%2==1) {
//             for(int j=0; j<=i; j++) ans += nums[j];
//             break;
//         }
//     }
//     if(ans.size()==0) cout << -1 << endl;
//     else cout << ans << endl;
// }

// Q5
// class TreeNode {
//     public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int data) {
//         val = data;
//         left = right = nullptr;
//     }
// };

// class Solution {
// public:
//     void inOrderTraversal(TreeNode* node, vector<int>& inOrder) {
//         if(!node) return;
//         inOrderTraversal(node->left, inOrder);
//         inOrder.push_back(node->val);
//         inOrderTraversal(node->right, inOrder);
//     }
//     int findCeil(vector<int>& inOrder, int key) { // Smallest value greater than or equal to the key
//         int ans = -1;
//         int low = 0;
//         int high = inOrder.size()-1;
//         while(low<=high) {
//             int mid = low + (high-low)/2;
//             if(inOrder[mid]<key) low = mid+1;
//             else { // inOrder[mid] >= key
//                 ans = inOrder[mid];
//                 high = mid-1;
//             }
//         }
//         return ans;
//     }
//     int findFloor(vector<int>& inOrder, int key) { // Greatest value smaller than or equal to the key
//         int ans = -1;
//         int low = 0;
//         int high = inOrder.size()-1;
//         while(low<=high) {
//             int mid = low + (high-low)/2;
//             if(inOrder[mid]>key) high = mid-1;
//             else { // inOrder[mid] <= key
//                 ans = inOrder[mid];
//                 low = mid+1;
//             }
//         }
//         return ans;
//     }
//     pair<int, int> floorAndCeil(TreeNode* root, int key) {
//         vector<int> inOrder;
//         inOrderTraversal(root, inOrder);
//         // InorderTraversal of a BST is sorted
//         int floor = findFloor(inOrder,key);
//         int ceil = findCeil(inOrder,key);
//         return {floor, ceil};
//     }
// };

// Q6
string shortestPalindrome(const string& s) {
    //write your code here...
    int n = s.size();
    int idx = 0;
    for(int i=n-1; i>=0; i--) {
        int low = 0, high = i;
        bool isPalindrome = true;
        while(low<high) {
            if(s[low]!=s[high]){
                isPalindrome = false;
                break;
            } 
            low++;
            high--;
        }
        if(isPalindrome) {
            idx = i;
            break;
        }
    }
    string ans = "";
    for(int i=n-1; i>idx; i--) {
        ans += s[i];
    }
    ans += s;
    return ans;
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

    return 0;
}
