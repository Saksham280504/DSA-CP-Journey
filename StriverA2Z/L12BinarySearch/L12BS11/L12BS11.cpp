#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int findNthPower(int i, int n) {
    int NthPower  = 1;
    while(n>0) {
        NthPower = NthPower*i;
        n--;
    }
    return NthPower;
}
// This function takes TC-> O(N)

int powerExponential(int i, int n) {
    int NthPower = 1;
    while(n > 0) {
        if(n%2==1) {
            NthPower = NthPower*i;
            n--;
        }
        else {
            i = i*i;
            n = n/2;
        }
    }
    return NthPower;
}
// This function takes TC-> O(log2(N))

int findNthRootUsingBinarySearch(int m, int n) {
    int low = 1;
    int high = m;

    while(low<=high) {
        int mid = (low+high)/2;
        if(findNthPower(mid,n) == m) return mid;
        else if(findNthPower(mid, n) < m) low = mid+1;
        else high = mid-1;
    }

    return -1;
}

int RootStatus(int mid, int n, int m) {
    int ans = 1;
    while(n>0) {
        ans = ans*mid;
        if(ans > m) return 2;
    }
    
    if(ans == m) return 1;
    return 0;
}

int OptimisedRootMethod(int m, int n) {
    int low = 1;
    int high = m;
    while(low<=high) {
        int mid = (low+high)/2;
        if(RootStatus(mid,n,m)==1) return mid;
        else if(RootStatus(mid,n,m)==0) low =mid+1;
        else high = mid-1;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m;
    cin >> m;

    int n;
    cin >> n;

    // To find Nth root of an Integer

    // Naive Method (Linear Search) 

    // for(int i=1; i<=m; i++) {
    //     if(findNthPower(i,n)==m) {
    //         cout << i << endl;
    //         return 0;
    //     }
    //     else if(findNthPower(i,n)>m) {
    //         cout << -1 << endl;
    //         return 0;
    //     }
    //     else continue;
    // }

    // TC -> O(M*N) 
    // This TC can be further optimised to O(Mlog2(N)) using the powerExponential function written above

    // Binary Search Method

    // int NthRoot = findNthRootUsingBinarySearch(m,n);

    // if(NthRoot == -1) cout << "Root Doesn't exist" << endl;
    // else cout << NthRoot << endl;

    // TC -> O(log2(M)*N)
    // This can be optimised to O(log2(M)*log2(N)) by using the powerExponential function written above

    // Now, this will be wrong because it will cause overflow case when high i.e. m is very large(near about 10^9) and that is when our code will fail, to save ourselves from this issue, we will use the further optimised code, where we take care about the fact that overflow doesn't occur

    
    int NthRoot = OptimisedRootMethod(m,n);

    if(NthRoot == -1) cout << "Root Doesn't exist" << endl;
    else cout << NthRoot << endl;
    return 0;
}
