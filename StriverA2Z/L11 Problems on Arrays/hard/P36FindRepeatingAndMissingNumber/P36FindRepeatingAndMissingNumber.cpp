#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

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
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    // brute-force method
    // int missing=-1;
    // int repeating=-1;
    // for(int i=1; i<=n; i++) {
    //     int count = 0;
    //     for(int j=0; j<n; j++) {
    //         if(arr[j]==i) count++;
    //     }
    //     if(count == 0) missing = i;
    //     if(count == 2) repeating = i;
    //     if(repeating != -1 && missing != -1) break;
    // }

    // TC -> O(N*N)
    // SC -> O(1)

    // Better approach (Hashing)
    
    // int HashArr[n+1] = {0};

    // for(int i=0; i<n; i++) {
    //     HashArr[arr[i]]++;
    // }
    // int missing = -1;
    // int repeating = -1;
    // for(int i=1; i<n; i++) {
    //     if(HashArr[i] == 0) missing = i;
    //     if(HashArr[i] == 2) repeating = i;
    //     if(missing != -1 && repeating!= -1) break;
    // }

    // TC -> O(2N)
    // SC ->O(N)

    // Optimal Approach (Mathematical Approach)

    // long long S = 0, S2 = 0;

    // for(int i=0; i<n; i++) {
    //     S += arr[i];
    //     S2 += (long long)arr[i] * (long long)arr[i];
    // }

    // long long Sn = (n*(n+1))/2;
    // long long S2n = (n*(n+1)*((2*n)+1))/6;

    // long long val1, val2;

    // val1 = S - Sn; // X - Y
    // val2 = S2 - S2n; // X2 - Y2
    // val2 = val2/val1; // X + Y

    // long long repeating = (val1 + val2)/2; // X
    // long long missing = val2 - repeating; // Y

    // TC -> O(N)
    // SC -> O(1)

    // Optimal Approach (XOR method)

    int xr = 0;
    for(int i = 0; i<n; i++) {
        xr = xr^arr[i];
        xr = xr^(i+1);
    }

    int binaryIndex = 0;

    while(1) {
        if((xr & (1<<binaryIndex))!=0)break;
        binaryIndex++;
    } // From here I will get the right most binaryIndex needed for further XOR procedure 

    int zero = 0;
    int one = 0;

    for(int i=0; i<n; i++) {
        if((arr[i] & (1<<binaryIndex)) == 0) zero = zero ^ arr[i]; // By doing this, I don't have to store the numbers
        else one = one ^ arr[i];
        if(((i+1) & (1<<binaryIndex)) == 0) zero = zero ^ (i+1); // By doing this, I don't have to store the numbers
        else one = one ^ (i+1);
        }

    int count = 0;

    for(int i=0; i<n; i++) {
        if(arr[i]==zero) count++;
    }
    int missing, repeating;
    if(count == 0) {
        missing = zero;
        repeating = one;
    }
    else {
        missing  = one;
        repeating = zero;
    }

    // TC -> O(3N)
    // SC -> O(1)

    cout << "MISSING: " << missing << endl;
    cout << "REPEATING: " << repeating << endl;
    return 0;
}


// XOR:

// 0 ^ 0 -> 0
// 1 ^ 0 -> 1
// 0 ^ 1 -> 1
// 1 ^ 1 -> 0
// 0 ^ NUM -> NUM
// NUM ^ NUM -> 0