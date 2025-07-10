#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void selection_sort(int arr[],int n) {
    for(int i=0; i<n-1; i++) {
        int mini = i;
        for(int j=i; j<n; j++) {
            if(arr[j] < arr[mini]) mini = j;
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;
        }
    }
}

void bubble_sort(int arr[], int n) {
    for(int i=n-1; i>0; i--) {
        int didSwap = 0;
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if(didSwap==0) break;
        cout << "runs\n";
    }
}

void recursive_bubble_sort(int arr[], int n) {
    if(n==1) return;
    int didSwap = 0;
    for(int j=0; j<n-1; j++) {
        if(arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            didSwap = 1;
        }
    }

    if(didSwap==0) return;

    recursive_bubble_sort(arr, n-1);
}


void insertion_sort(int arr[], int n) {
    for(int i=0; i<=n-1; i++) {
        int j =i;
        while(j>0 && arr[j-1] > arr[j]) {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void recursive_insertion_sort(int arr[], int n) {
    if (n <= 1) return;
    recursive_insertion_sort(arr, n - 1);
    int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
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
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    recursive_insertion_sort(arr,n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
