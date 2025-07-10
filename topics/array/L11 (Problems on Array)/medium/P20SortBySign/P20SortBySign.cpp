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


    // 1st Variety
    // Brute-force method

    // vector<int> posArr;
    // vector<int> negArr;

    // for(int i=0; i<n; i++) {
    //     if(arr[i] > 0) posArr.push_back(arr[i]);
    //     else negArr.push_back(arr[i]); 
    // }

    // for(int i=0; i<n/2; i++) {
    //     arr[2*i] = posArr[i];
    //     arr[2*i+1] = negArr[i];
    // }

    // TC -> O(N) + O(N/2)
    // SC -> O(N)

    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }

    // Optimal solution

    // vector<int> ansArr(n,0);
    // int posIndex = 0;
    // int NegIndex = 1;

    // for(int i=0; i<n; i++) {
    //     if(arr[i] > 0) {
    //         ansArr[posIndex] = arr[i];
    //         posIndex = posIndex + 2;
    //     }
    //     else {
    //         ansArr[NegIndex] = arr[i];
    //         NegIndex = NegIndex + 2;
    //     }
    // }

    // TC -> O(N)
    // SC - > O(N)

    // for(int i=0; i<n; i++) {
    //     cout << ansArr[i] << " ";
    // }

    // 2nd Variety

    vector<int> posArr;
    vector<int> negArr;
    int ShorterLength = 0;

    for(int i=0; i<n; i++) {
        if(arr[i] > 0) posArr.push_back(arr[i]);
        else negArr.push_back(arr[i]);
    }

    int posLength = posArr.size();
    int negLength = negArr.size();
    ShorterLength = min(posLength, negLength);

    for(int i=0; i<2*ShorterLength; i++) {
        if(i%2==0) arr[i] = posArr[i/2];
        else arr[i] = negArr[i/2];
    }
    int pointer = 2*ShorterLength;
    if(posLength > negLength) {
        for(int i=ShorterLength; i<posLength; i++) {
            arr[pointer] = posArr[i];
            pointer++;
        }
    }
    else {
        for(int i=ShorterLength; i<negLength; i++) {
            arr[pointer] = negArr[i];
            pointer++;
        } 
    }

    // TC -> O(2N)
    // SC -> O(N)
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
