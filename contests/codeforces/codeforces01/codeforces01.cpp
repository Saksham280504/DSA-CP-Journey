#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(int n) {
    int arr[n];
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i]==0){
            if(i==n-1) {
                counter+=1;
            }
            else if(arr[i+1]==0){
                cout << "YES" << endl;
                break;
            } else {
                counter+=1;
            }
        }
        else {
            counter+=0;
        }
    }

    if(counter == 0) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    counter = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);    
    freopen("output.txt", "w", stdout);  
#endif

    ll t;
    cin >> t;
    for(int i=1;i<=t;i++) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}