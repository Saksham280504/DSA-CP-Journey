#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Trial - 1

class Solution {
private:
    int n;
    vector<int> dp;
    int isPossible(int idx, string s, int minJ, int maxJ) {
        if(idx==0) return dp[idx] = 1;
        if(dp[idx]!=-1) return dp[idx];
        if(s[idx]=='1') return dp[idx] = 0;
        bool can = false;
        for(int i=idx-minJ; i>=max(0,idx-maxJ); i--) {
            can |= isPossible(i,s,minJ,maxJ);
        }
        return dp[idx] = can;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        n = s.size();
        dp.assign(n,-1);
        return isPossible(n-1,s,minJump,maxJump);
    }
};

// Trial - 2
class Solution {
private:
    int n;
    vector<int> dp;
public:
    bool canReach(string s, int minJump, int maxJump) {
        n = s.size();
        dp.assign(n,0);
        dp[0] = 1;
        for(int idx=1; idx<n; idx++) {
            if(s[idx]=='1') continue;
            bool can = false;
            for(int i=idx-minJump; i>=max(0,idx-maxJump); i--) {
                if(s[i]=='0') {
                    can |= dp[i];
                }
            }
            dp[idx] = can;
        }
        return dp[n-1];
    }
};

// Both trial-1 (Recursive memoization) and trial-2 (Tabulation) gave MLEs and TLEs because of very big recursive depths of O(N^2) solution, as 0<minJump<=maxJump<n

// Therefore here rather than using DP we will use BFS+Sliding window approach

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]!='0') return false;
        queue<int> q;
        q.push(0);
        int farthest = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr==(n-1)) return true;
            int start = max(curr+minJump,farthest+1);
            int end = min(curr+maxJump,n-1);
            for(int i=start; i<=end; i++) {
                if(s[i]=='0') {
                    q.push(i);
                }
            }
            farthest = max(farthest,end);
        }

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
