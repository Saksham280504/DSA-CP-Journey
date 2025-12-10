#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void swapGreater(vector<int>& arr1, vector<int>& arr2, int index1, int index2) {
    if(arr1[index1] >= arr2[index2]) swap(arr1[index1], arr2[index2]);
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

    int n;
    cin >> n;
    vector<int> arr1;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr1.push_back(nums);
    }

    int m;
    cin >> m;
    vector<int> arr2;
    for(int i=0; i<m; i++) {
        int nums;
        cin >> nums;
        arr2.push_back(nums);
    }

    // Initial approach

    // int arr3[n+m];
    // int left = 0;
    // int right = 0;
    // int index = 0;
    // while(left < n && right < m) {
    //     if(arr1[left] <= arr2[right]) {
    //         arr3[index] = arr1[left];
    //         left++;
    //         index++;
    //     }
    //     else {
    //         arr3[index] = arr2[right];
    //         right++;
    //         index++;
    //     }
    // }
    // while(left < n) {
    //     arr3[index++] = arr1[left++];
    // }
    // while(right < m) {
    //     arr3[index++] = arr2[right++];
    // }

    // for(int i=0; i<n+m; i++) {
    //     if(i<n) arr1[i] = arr3[i];
    //     else arr2[i-n] = arr3[i];
    // }
    
    // TC -> O(2*(n+m))
    // SC -> O(n+m) -> We have to remove this extra space

    // Final approach

    // Optimal Solution - 1

    // int left = n-1;
    // int right = 0;
    // while(left >=0 && right < m) {
    //     if(arr1[left]>=arr2[right]) {
    //         swap(arr1[left],arr2[right]);
    //         left--;
    //         right++;
    //     }
    //     else break;
    // }

    // sort(arr1.begin(), arr1.end());
    // sort(arr2.begin(), arr2.end());

    // TC -> O(NlogN + MlogM + min(N,M))
    // SC -> O(1)

    // Optimal Solution - 2 (Gap Method)

    int length = n+m;
    int gap = (length/2) + (length%2);

    while (gap > 0) {
        int left = 0;
        int right  = left + gap;

        while(right < length) {
            // arr1  & arr2
            if(left < n && right >= n) {
                swapGreater(arr1, arr2,left, right - n);
            }
            // arr2  & arr2
            else if(left >= n) {
                swapGreater(arr2, arr2,left-n, right - n);
            }
            // arr1 & arr1
            else {
                swapGreater(arr1, arr1,left, right);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap/2) +(gap%2);
    }

    // TC-> O((log2(n+m))*(n+m)) whenever looping occurs on division by d on a number num, then the TC for that loop is logd(num)
    // SC-> O(1)

    for(int i=0; i<n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for(int i=0; i<m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;    
    return 0;
}
