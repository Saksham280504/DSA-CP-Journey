#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// Memoization Solution
class Solution {
    private:
    bool check(int ind, int cnt, string s, int n, vector<vector<int>> & dp) {
        if(cnt<0) return false;
        if(ind==n) return (cnt==0);
        if(dp[ind][cnt]!=-1) return dp[ind][cnt];
        else if(s[ind]=='(') {
            return check(ind+1,cnt+1,s,n,dp);
        }
        else if(s[ind]==')') {
            return check(ind+1,cnt-1,s,n,dp);
        }
        return check(ind+1,cnt+1,s,n,dp) | check(ind+1,cnt-1,s,n,dp) | check(ind+1,cnt,s,n,dp);
    } 
    public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return check(0,0,s,n,dp);
    }

    // TC -> O(N*N)
    // SC -> O(N*N)
};
class Solution {
    public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;

        for(auto it: s) {
            if(it=='(') {
                mini++;
                maxi++;
            }
            else if(it==')') {
                mini--;
                maxi--;
            }
            else {
                mini--; 
                maxi++; // Our main aim is to create the largest possible positive range of values for a string.
            }
            if(mini<0) mini = 0; // mini was taking the maximum chances of reducing itself, so it mini somehow reaches < 0, that means that when we took the path with maximum -1s(')'), that's when we came <0, we can prevent that condition by reducing one -1s to make mini again equal to 0
            if(maxi<0) return false; // maxi was taking minimum chances of reducing itself, so if in that path too maxi becomes <0, then that string is for sure not valid as there is no astric('*') to prevent it.
        }
        if(mini==0) return true;
        return false;

        // TC -> O(N)
        // SC -> O(1)
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
