#include<bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main() to int32_t main()
// #define endl '\n'

void doSomething(int arr[]) {
    arr[0] += 100;
    cout << "Value inside the function: " <<arr[0] << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
      int n = 5;
      int arr[n];
      for (int i = 0; i < n; i++){
        cin >> arr[i];
      }
      cout << "Value inside main before function: "<< arr[0] << endl;

      doSomething(arr);

      cout << "Value inside main after function: "<< arr[0] << endl;
    return 0;
}
// Arrays
// Always remember that if in an array, value for a certain is not initialized, then computer provides it on its own.

// For an array, its consecutive values are always stored at consecutive locations, but it is not certain where its first value (i.e. the zeroth index value) is stored.

// Functions: Functions are set of code which performs something for you
// Functions are used to modularize code
// Functions are used to increase readability
// Functions are used to use same code multiple times
// void -> which does not returns anything
// return -> which will return something for sure
// parameterised
// non-parameterised

// There are two types of parameterised functions:

// 1. Pass by value:- Here, a copy of the value of the original parameter is sent, so the original value stays the same.

// 2. Pass by reference:- Here, the original value is sent to the function, so the changes are made in then original value.

// For Pass by value, you write "datatype variable-name" inside the ().
// For Pass by reference, you write "datatype &variable-name" inside the ().

// For array always remember that whenever an array is used as a parameter, it is always pass by reference but no '&' is used.

// Whenever a function is called, first the context of int main() is stopped and the context of function is executed and then afterwards the context of int main() is resumed.

// for string, use ""
// for char, use ''
