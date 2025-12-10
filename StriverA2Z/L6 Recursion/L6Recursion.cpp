#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

void printName(int n){
    if(n==0) return;
    cout << "Saksham is here" << endl;
    n--;
    printName(n);
}
void printNumber(int s, int n){
    // approach-1 (incremental method)
    // if(n-s<0) return;
    // cout << s << endl;
    // printNumber(n,s+1);
    // // pass 1 in place of s

    //approach-2 (backtracking method)
    if(s<1) return;
    printNumber(s-1,n);
    cout << s << endl;
}
void printNumberDescend(int s,int n){
    
    //approach-1 (decremental method)
    // if(n==0) return;
    // cout << n << endl;
    // n--;
    // printNumberDescend(n);
    //approach-2 (backtracking method)
    if(s>n) return;
    printNumberDescend(s+1,n);
    cout << s << endl;
}
int sumOfNaturalNumbers(int n) {
    //approach-1 (parameterised method) // here, pass i=n, and sum=0
    // if(i<1) {
    //     cout << sum << endl;
    //     return;
    // }
    // sumOfNaturalNumbers(i-1,sum+i);

    //approach-2 (functional method)
    if(n==0) return 0;
    return n + sumOfNaturalNumbers(n-1);
}
void factorialOfNaturalNumbers(int i, int factorial) {
    // approach-1 (functional method)
    // if(n==0) return 1;
    // return n*factorialOfNaturalNumbers(n-1);

    // approach-2 (parameterised method)
    if(i<1) {
        cout << factorial << endl;
        return;
    }
    return factorialOfNaturalNumbers(i-1,factorial*i);
}
void reverseAnArray(int arr[], int i, int n){

    //approach-1
    // if(l>=r) return;
    // swap(arr[l],arr[r]);
    // reverseAnArray(arr,l+1,r-1);
    
    //approach-2
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    return reverseAnArray(arr,i+1,n);
}
bool checkPalindrome(string s, int i) {
    int n = s.size();
    if(i>=n/2) return 1;
    if(s[i]!= s[n-i-1]) {
        return 0;
    }
    return checkPalindrome(s,i+1);
}
int Fibonacci(int n) {
    if(n<=1) return n;
    int last = Fibonacci(n-1);
    int slast = Fibonacci(n-2);
    return last + slast;
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
    for(int i=1; i<=t; i++){
        int n;
        cin >> n;
        int f = Fibonacci(n);
        cout << f << endl;
    }

    return 0;
}
