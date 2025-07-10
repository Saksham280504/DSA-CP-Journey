#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

int numberOfOperations(vector<int>& arr,int counter) {
    int a = *arr.begin();
    int b = *(arr.end()-1);
    if((a+b)%2==0) return counter;
    counter++;
    
    if(a%2==0) {
        int odd = 1;
        int even = 1;
        for(int i=1; i <arr.size(); i++) {
            if(arr[i]%2!=0) {
                odd = i;
                break;
            }
        }
        for(int j=1; j<arr.size();j++) {
            if(arr[arr.size()-1-j]%2==0) {
                even = j;
                break;
            }
        }
        if(odd < even) {
            arr.erase(arr.begin());
            return numberOfOperations(arr,counter);
        }
        else {
            arr.erase(arr.end()-1);
            return numberOfOperations(arr, counter);
        }
    }
    else {
        int odd=1;
        int even=1;
        for(int i=1; i <arr.size(); i++) {
            if(arr[i]%2==0) {
                even = i;
                break;
            }
        }
        for(int j=1; j<arr.size();j++) {
            if(arr[arr.size()-1-j]%2!=0) {
                odd = j;
                break;
            }
        }
        if(odd < even) {
            arr.erase(arr.end()-1);
            return numberOfOperations(arr,counter);
        }
        else {
            arr.erase(arr.begin());
            return numberOfOperations(arr, counter);
        }
    }
}   
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int j=0; j<n; j++){
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end());
        int counter = 0;
        int o = numberOfOperations(arr, counter);
        cout << o << endl;
    }
    return 0;
}
