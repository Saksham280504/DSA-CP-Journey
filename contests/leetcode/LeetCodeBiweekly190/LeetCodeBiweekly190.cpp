#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Q1
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        char sourceColor, targetColor;
        sourceColor = ((source[0]+source[1])&1) ? 'W' : 'B';
        targetColor = ((target[0]+target[1])&1) ? 'W' : 'B';
        if(sourceColor!=targetColor) return -1;
        // Now either both are 'B' or both are 'W' and for each color block we have 2 diagonals -> y+x = constant or y-x+8 = constant
        // If they share a diagonal, we will reach in 1 move or if not then in 2 moves
        int sy = source[0], sx = source[1];
        int ty = target[0], tx = target[1];
        return (((ty+tx)==(sy+sx)) || ((ty-tx+8)==(sy-sx+8))) ? 1 : 2;
    }
};

// Q2
class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int maxScore = INT_MIN;
        // Case-1 Don't remove any element
        vector<int> prefix1(n), suffix1(n);
        prefix1[0] = nums[0], suffix1[n-1] = nums[n-1];
        for(int i=1; i<n; i++) {
            prefix1[i] = __gcd(prefix1[i-1],nums[i]);
        }
        for(int i=n-2; i>=0; i--) {
            suffix1[i] = __gcd(suffix1[i+1],nums[i]);
        }
        int cnt1 = 0;
        for(int i=0; i<(n-1); i++) {
            if(prefix1[i]==suffix1[i+1]) cnt1++;
        }
        maxScore = max(maxScore,cnt1);
        
        // Case-2 Remove 1 Element
        for(int i=0; i<n; i++) {
            vector<int> arr;
            for(int j=0; j<n; j++) {
                if(j!=i) arr.push_back(nums[j]);
            }
            int m = n-1;
            vector<int> prefix(m);
            vector<int> suffix(m);
            prefix[0] = arr[0];
            suffix[m-1] = arr[m-1];
            for(int k=1; k<m; k++) {
                prefix[k] = __gcd(prefix[k-1],arr[k]);
            }
            for(int k=(m-2); k>=0; k--) {
                suffix[k] = __gcd(suffix[k+1],arr[k]);
            }
            int cnt = 0;
            for(int i=0; i<(m-1); i++) {
                if(prefix[i]==suffix[i+1]) cnt++;
            }
            maxScore = max(maxScore,cnt);
        }
        return maxScore;
    }
};

// Q3
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int x: nums) {
            string str = "";
            while(x>0) {
                int i=0;
                while((1<<i)<=x) {
                    i++;
                    if(i==26) break;
                }
                i--;
                char chToCome = 'a' + i;
                str += chToCome;
                x -= (1<<i);
            }
            ans.push_back(str);
        }
        return ans;
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

    // 1. ChessBoard Knowledge
    // 2. gcd STL->(__gcd(num1,num2)), also remember if there are exist an array arr with gcd of all elements (__gcd(arr)), and now we want to find the gcd of all elements in arr and one more element ele, then that will be = __gcd(__gcd(arr),ele)
    // 3. Bit Algebra
    // 4. Sparse Table (Range Queries) -> Don't know

    return 0;
}
