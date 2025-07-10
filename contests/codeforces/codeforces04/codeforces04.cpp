#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
void isSquarePossible(vector<int>& arr) {

    int MaxiLength = arr[0];
    int MaxiBreadth = arr[1];

    if(MaxiLength > MaxiBreadth) {
        if(arr[2]==MaxiLength && arr[4]==MaxiLength) {
            int BreadthSum = MaxiBreadth + arr[3] + arr[5];
            if(BreadthSum==MaxiLength) {
                cout << "YES" << endl;
                return;
            }
            cout << "NO" << endl;
            return;
        }
        else if((arr[2]<MaxiLength && arr[4]==MaxiLength) || (arr[2]==MaxiLength && arr[4]<MaxiLength)) {
            cout << "NO" << endl;
            return;
        }
        else if(arr[2]+arr[4]==MaxiLength) {
            int BreadthSum = 0;
            for(int i=3; i<6; i=i+2) {
                BreadthSum = MaxiBreadth + arr[i];
                if(BreadthSum==MaxiLength) {
                    cout << "YES" << endl;
                    return;
            }
            }
            cout << "NO" << endl;
            return;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    } else {
        if(arr[3]==MaxiBreadth && arr[5]==MaxiBreadth) {
            int LengthSum = MaxiLength + arr[2] + arr[4];
            if(LengthSum==MaxiBreadth) {
                cout << "YES" << endl;
                return;
            }
            cout << "NO" << endl;
            return;
        }
        else if((arr[3]<MaxiBreadth && arr[5]==MaxiBreadth) || (arr[3]==MaxiBreadth && arr[5]<MaxiBreadth)) {
            cout << "NO" << endl;
            return;
        }
        else if(arr[5]+arr[3]==MaxiBreadth) {
            int LengthSum = 0;
            for(int i=2; i<6; i=i+2) {
                LengthSum = MaxiLength + arr[i];
                if(LengthSum==MaxiBreadth) {
                    cout << "YES" << endl;
                    return;
            }
            }
            cout << "NO" << endl;
            return;
        }
        else {
            cout << "NO" << endl;
            return;
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

    // your code here

    // Problem-1

    long long t;
    cin >> t;
    for(int i=0; i<t; i++) {
        vector<int> arr;
        for(int i=0;i<6;i++) {
            int nums;
            cin >> nums;
            arr.push_back(nums);
        }

        isSquarePossible(arr);
    }

    return 0;
}
