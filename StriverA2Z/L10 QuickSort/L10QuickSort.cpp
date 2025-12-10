#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int Partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j) {
        while(i<=high-1 && arr[i]>=pivot) {
            i++;
        }
        while(j>=low+1 && arr[j]<pivot) {
            j--;
        }
        if(i<j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp1 = arr[low];
    arr[low] = arr[j];
    arr[j]= temp1;
    return j;
}

void quickSort (vector<int>& arr, int low, int high) {
    if(low<high) {
        int PIndex = Partition(arr, low, high);
        quickSort(arr, low, PIndex-1);
        quickSort(arr, PIndex+1, high);
    }
    return;
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
    vector <int> arr;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cout << "Array before sorting: ";
    for(int i=0; i<n; i++) {
     cout << arr[i] << " ";
     
    }
    cout << endl;
    quickSort(arr,0,n-1);
    cout << "Array after sorting: ";
    for(int i=0; i<n; i++) {
     cout << arr[i] << " ";
     
    }
    cout << endl;
    return 0;
}

// One thing that is very good about the quickSort is that as it performs division while it is giving us the partition index, it is also performing sorting side-by-side, due to which the code becomes much more compact than merge sort. Also since no temperory array is formed, therefore only auxillary stack space is occupied due to which the space complexity becomes O(1).