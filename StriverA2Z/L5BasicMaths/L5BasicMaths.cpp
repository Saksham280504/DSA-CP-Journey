#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl  '\n'

/*
void NumberofDigits(int n){
    int counter=0;
    while(n>0){
        counter++;
        n = n/10;
    }
    cout << "number of digits: " << counter << endl;
}
*/
/*
void ReverseNumber(int n){
    int n1 = n;
    int n3 = 0;
    while(n1>0){
        n3= n3*10 + n1%10;
        n1 = n1/10;
    }
    cout << n3 << endl;
}
*/
/*
void CheckPalindrome(int n){
    int n1 = n;
    int n3 = 0;
    while(n1>0){
        n3= n3*10 + n1%10;
        n1 = n1/10;
    }
    if(n3==n) cout << "It's a Palindrome" << endl;
    else cout << "It's not a Palindrome" << endl;
}
*/
/*
void ArmstrongNumber(int n){
    int n1 =n;
    int n3 = 0;
    int counter=0;
    while(n1>0){
        n1 = n1/10;
        counter++;
    }
    n1 = n;
    while(n1>0){
        int n2 = n1%10;
        n3 = n3 + pow(n2,counter);
        n1=n1/10;
    }
    if(n3 == n) cout << "Armstrong number" << endl;
    else cout << "Not an Armstrong number" << endl;
}
*/
/*
void printDivisors(int n){
    // cout << "divisors of n are: ";
    // for(int i=1;i<=n;i++){
    //     if(n%i==0) cout << i << " ";
    // }
    // cout << endl;
    // The above method is okay but there the time complexity is O(n), which we don't want. So, let's try a better optimised approach:
    
    cout << "divisors of " << n << " are: ";
    vector<int> v;
    // O(sqrt of n)
    for(int i=1; i*i<=(n); i++){
        if(n%i==0){
            v.emplace_back(i);
            if(n/i!=i) v.emplace_back(n/i);
        } 
    }
    // O(number of factors*(log number of factors))
    sort(v.begin(), v.end());

    // O(number of factors)
    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;
    // So now the time complexity becomes: O(sqrt of n) + O(number of factors*(log number of factors)) + O(number of factors), which is far less then O(n).
}
*/
/*
void checkPrime(int n){
    int counter=0;
    for(int i=1; i*i<=n; i++){
        if(n%i==0) {
            counter++;
            if(n/i!=i) counter++;
        } 
    }
    if(counter==2) {
        cout << n << " is prime " << endl; 
    }
    else {
        cout << n << " is not prime " << endl;
    }
}
*/

void findGCD(int n, int m) {
    // approach-1;
    // vector<int> v1;
    // vector<int> v2;
    // int counter1 = 0;
    // int counter2 = 0;
    // for(int i=1; i*i<=n; i++){
    //     if(n%i==0) {
    //         v1.emplace_back(i);
    //         counter1++;
    //         if(n/i!=i) {
    //             v1.emplace_back(n/i);
    //             counter1++;
    //         }
    //     }
    // }
    // for(int i=1; i*i<=m; i++){
    //     if(m%i==0) {
    //         v2.emplace_back(i);
    //         counter2++;
    //         if(m/i!=i) {
    //             v2.emplace_back(m/i);
    //             counter2++;
    //         }
    //     }
    // }
    // int GCD = 0;
    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());
    //     for(auto it1: v1){
    //         for(auto it2: v2){
    //             if(it1 == it2)
    //             GCD = it1;
    //         }
    //     }
    // cout << "The GCD of " << n << " & " << m << " is: " << GCD << endl;

    // approach-2:
    // int GCD = 1;
    // for(int i =min(n,m); i>=1; i--){
    //     if(n%i==0 && m%i==0){
    //         GCD = i;
    //         break;
    //     }
    // }
    // cout << "GCD of " << n << " & " << m << " is: " << GCD << endl;

    // approach-3:
    int GCD = 0;
    if(n==0) {
        GCD = m;
        cout << GCD << endl;
    }
    else if(n > m) {
        findGCD(n%m, m);
    }
    else {
        findGCD(m%n,n);
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
    for(int i=1;i<=t;i++){
        int n,m;
        cin >> n >> m;
        findGCD(n,m);
    }

    return 0;
}
