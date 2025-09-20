#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
int fiboprev(int n) {
    if(n<=1) return n;
    else return fiboprev(n-1) + fiboprev(n-2);
}

int fiboDP(int n, vector<int>& dp) {
    if(n<=1) return n;
    
    // Step-2: Checking if the sub-problem has already been solved
    if(dp[n]!=-1) return dp[n];

    // Step-1: Storing the value of solved sub-problem
    return dp[n] = fiboDP(n-1,dp) + fiboDP(n-2,dp);
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
    // DP -> Memoization(Top-Down), Tabulation(Bottom-Up)

    // Recursion playlist is required

    // P01 - Fibonacci Number

    // Whenever we end up solving same sub-problems again and again, that condition is known as overlapping sub-problems. To prevent this, we use memoization where we tend to store the value of sub-problems in some map/table.

    // What is Memoization?
    // Evey time a problem was solved, I tend to store the value of that problem in an array called dp-array, and whenever a problem was called, I would check for its value in the dp-array, if present I would directly use that value, otherwise I will solve its value and then store it in the dp-array. This is called Memoization.

    int n;
    cin >> n;
    // Previously we solved the problem like this:
    int x = fiboprev(n);
    cout << x << endl;

    // Now, we will use DP to solve this problem:

    // Step-0: Declaring DP Array
    vector<int> dp(n+1,-1);
    int y = fiboDP(n,dp);
    cout << y << endl;
    // TC -> O(N)
    // SC -> O(N) (stack-space) + O(N) (DP-Array)

    // Stack-space in recursion refers to the memory allocated on the call stack to manage recursive function calls. When a function calls itself repeatedly, as in recursion, each call requires its own dedicated space on this stack.

    // Conversion of Recursive solution to tabulation form

    // Recursive approach goes from answer to base-case and then comes back (top-down).

    // Tabular approach goes from base-case to answer (bottom-up).

    // Tabular approach -> SC(N) approach:

    vector<int> dpTab(n+1,-1);
    dpTab[0] = 0;
    dpTab[1] = 1;

    for(int i=2; i<=n; i++) {
        dpTab[i] = dpTab[i-1] + dpTab[i-2];
    }
    cout << dpTab[n] << endl;
    // TC -> O(N)
    // SC -> O(N)

    // Tabular approach -> SC(1) approach:

    int prev2 = 0;
    int prev1 = 1;
    int curi = -1;
    for(int i=2; i<=n; i++) {
        curi = prev1 + prev2;
        prev2 = prev1;
        prev1 = curi;
    }
    cout << curi << endl;

    // TC -> O(N)
    // SC -> O(1)
    return 0;
}
