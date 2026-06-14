#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    ll largest_sum = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]>(largest_sum+1)) {
            cout << largest_sum+1 << endl;
            return 0;
        }
        largest_sum += arr[i];
    }

    cout << largest_sum+1 << endl; // If till the largest index it never happened that arr[i]<largest_sum+1, then the final answer will be total_sum+1

    // 1. All the elements are positive, thus the largest value of minimum sum not achievable from the sum of any subset of coins is (totalSum + 1)
    // 2. Sort the array so that you can look over the smallest possible integers first.
    // 3. Now if you are at index i, and the largest sum possilble till index i-1 is "largest_sum", then to check if largest_sum+1 is possible at the index i is that arr[i] must be <= largest_sum + 1

    // For eg. if sorted array -> [1,2,2,7,9]
    // Let largest_sum be initialized as 0.
    // At index 0, we see that arr[0]=1<=(largest_sum+1(0+1=1)), therefore we can generate all the sums possible in this range till this index [1...largest_sum+1].

    // largest_sum = 0 (initially)
    // Index  Checking   Posssible sums  Largest Sum
    // i=0 -> (1<=(0+1)) [1] -> largest_sum = 1
    // i=1 -> (2<=(1+1)) [1,2,3] -> largest_sum = 3
    // i=2 -> (2<=(3+1)) [1,2,3,4,5] -> largest_sum = 5
    // i=3 -> (7>(5+1))  (thus answer is 6)

    return 0;
}
