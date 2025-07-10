#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '\n'
/*
void print1(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}
*/
/*
void print2(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}
*/
/*
void print3(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
*/
/*
void print4(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
}
*/
/*
void print5(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j<=n-i+1){
                cout << "*" << " ";
            }
            else cout << " " << " ";
        }
        cout << endl;
    }
}
*/
/*
void print6(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j<=n-i+1){
                cout << j << " ";
            }
            else cout << " " << " ";
        }
        cout << endl;
    }
}
*/
/*
void print7(int n){ 
    for(int i = 1; i<=n; i++){
            for(int j = 1; j <=((2*n)-1); j++) {
    if(j>=1 && j<=(n-i)) {
        cout << " " << " ";
    } else if(j>=(n-i+1) && j<=(n+i-1)){
        cout << "*" << " ";
    } else {
        cout << " " << " ";
    }
}
cout << endl;
    }
}
*/
/* 
void print8(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(2*n)-1;j++){
            if(j>=1 && j<=(i-1)){
                cout << " " << " ";
            }
            else if(j>=i && j<=((2*n)-i)){
                cout << "*" << " ";
            }
            else {
                cout << " " << " ";
            }
        }
        cout << endl;
    };
}
*/
/*
void print9(int n){
    for(int i=1; i<=2*n; i++){
        if(i<=n){
        for(int j=1; j<=2*n-1;j++) {
            if(1<=j && j<=(n-i)){
                cout << " " << " ";
        }
            else if(n-i+1<=j && j<=n+i-1){
                cout << "*" << " ";
        } 
            else {
                cout << " " << " ";
        }
       }
    } else {
        int k = i-n;
        for(int j=1; j<=2*n-1;j++){
            if(1<=j && j<=k-1){
                cout << " " << " ";
            }
            else if(k<=j && j<=(2*n)-k){
                cout << "*" << " ";
            }
            else {
                cout << " " << " ";               
            }
        }
    }
    cout << endl;   
    }
};
*/
/*
void print10(int n){
    for(int i=1; i<=2*n-1; i++){
        if(i<=n){
            for(int j=1; j<=i;j++){
                cout << "*" << " ";
            }
        }
        else {
            int k =i-n;
            for(int j=1;j<=(n-k);j++){
                cout << "*" << " ";
            }
        }
        cout << endl;
    }
}
*/
/*
void print11(int n){
    // int start;
    // for(int i=1;i<=n;i++){
    //     if(i%2==0) start=0;
    //     else start = 1;
    //     for(int j=1; j<=i; j++){
    //         cout << start;
    //         start=1-start;
    //     }
    //     cout<< endl;
    // }
    for(int i=1; i<=n; i++){
        for(int j=1;j<=i;j++){
            if(i%2==0){
                if(j%2==0) cout << 1 << " ";
                else cout << 0 << " ";
            }
            else {
                if(j%2==0) cout << 0 << " ";
                else cout << 1 << " ";
            }
        }
        cout << endl;
    }
}
*/
/*
void print12(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=2*n; j++){
            if(j<=i){
                cout << j << " ";
            }
            else if(j<=2*n-i){
                cout << " " << " ";
            }
            else {
                cout << 2*n-j+1 << " ";
            }
        }
        cout << endl;
    }
}
*/
/*
void print13(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(i==1) cout << i+j-1 << " ";
            else cout << i+j-1+(((i-2)*(i-1))/2) << " ";
        }
        cout << endl;
    }
}
*/
/*
void print14(int n){
    for(int i=1; i<=n; i++){
        for(int j=1;j<=i;j++){
            int k = 65+j-1;
            cout << (char)k << " ";
        }
        cout << endl;
    }
}
*/
/*
void print15(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int k = 65+j-1;
            if(j<=n-i+1) cout << (char)k << " ";
            else cout << " " << " ";
        }
        cout << endl;
    }
}
*/
/*
void print16(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            int k = 65+i-1;
            cout << (char)k << " ";
        }
        cout << endl;
    }
}
*/
/*
void print17(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(2*n)-1; j++){
            if(j<=n-i) cout << " " << " ";
            else if(j<=n+i-1) {
                for(j=n-i+1;j<=n;j++){
                    int k=65+j-(n-i+1);
                    cout << (char)k << " ";
                }
                for(j=n+1;j<=n+i-1;j++){
                    int k = 65+(n+i-1)-j;
                    cout << (char)k << " ";
                }
            }
            else cout << " " << " ";
        }
        cout << endl;
    }
}
*/
/*
void print18(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            int k = 65+(n-i+j-1);
            cout << (char)k << " ";
        }
        cout << endl;
    }
}
*/
/*
void print19(int n){
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=2*n; j++){
            if(i<=n){
                if(j<=n-i+1) cout << "*";
                else if(j<=n+i-1) cout << " ";
                else cout << "*";
            }
            else {
                int k=i-n;
                if(j<=k) cout << "*";
                else if(j<=2*n-k) cout << " ";
                else cout << "*";
            }
        }
        cout << endl;
    }
}
*/
/*
void print20(int n){
    for(int i=1; i<=2*n-1; i++){
        for(int j =1; j<=2*n; j++){
            if(i<=n){
                if(j<=i) cout << "*";
                else if(j<=2*n-i) cout << " ";
                else cout << "*";
            }
            else {
                int k=i-n;
                if(j<=n-k) cout << "*";
                else if(j<=n+k) cout << " ";
                else cout << "*";
            }
        }
        cout << endl;
    }
}
*/
/*
void print21(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 || i==n) cout << "*";
            else {
                if(j==1 || j==n) cout << "*";
                else cout << " ";
            }
        }
        cout << endl;
    }
}
*/

void print22(int n){
    for(int i=1;i<=2*n-1; i++){
        for(int j=1; j<=2*n-1; j++){
            if(i<=n){
                if(j<=i) cout << n-j+1 << " ";
                else if(j<=2*n-1-i) cout << n-i+1 << " ";
                else cout << j-n+1 << " ";
            }
            else {
                int k=i-n;
                if(j<=n-k) cout << n-j+1 << " ";
                else if(j<=n+k-1) cout << k+1 << " ";
                else cout << j-n+1 << " ";
            }
        }
        cout << endl;
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

    // your code here
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
        int n;
        cin >> n;
        print22(n);
    }
    return 0;
}


