#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

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
    vector<int> arr;
    for(int i=0; i<n; i++) {
        int nums;
        cin >> nums;
        arr.push_back(nums);
    }

    // brute-force method
    // vector<int> ls;

    // for(int i=0; i<n ;i++) {
    //     if(ls.size()==0 || ls[0]!= arr[i]) {
    //         int counter = 1;
    //         for(int j=i+1; j<n; j++) {
    //             if(arr[j]== arr[i]) counter ++;
    //         }
    //         if(counter > n/3) ls.push_back(arr[i]);
    //     }
    //     if(ls.size()==2) break;
    // }

    // cout << ls[0] << " " << ls[1] << endl;

    // TC -> O(N*N)
    // SC -> O(2) -> O(1)

    // Better approach

    // map<int,int> mpp;

    // for(int i=0; i<n; i++) {
    //     mpp[arr[i]]++;
    //     int min = n/3 + 1;
    //     if(mpp[arr[i]]== min) cout << arr[i] << " ";
    // }

    // TC -> O(NlogN) (for ordered map)
    // TC -> O(N) (best & average case in unordered map)
    // TC -> O(N*N) (worst case in unordered map)
    // SC -> O(N) (worst case)

    // Optimal approach

    // We know that for MajorityELement(>n/3) problem, we will see atmost 2 elements in our answer
    // So, what we will do is firstly determine those 2 majority elements by counter method and then we will verify if the count of those elements is > n/3 or not.

    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;

    for(int i=0; i<n; i++) {
        if(cnt1==0 && arr[i]!=ele2) {
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2 ==0 && arr[i]!=ele1) {
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i]==ele1) cnt1++;
        else if(arr[i]==ele2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ls;
    cnt1 = 0;
    cnt2 = 0;

    for(int i=0; i<n; i++) {
        if(arr[i]==ele1) cnt1++;
        if(arr[i]==ele2) cnt2++;
    }
    int mini = n/3 + 1;
    if(cnt1 >=mini) ls.push_back(ele1);
    if(cnt2 >=mini) ls.push_back(ele2);

    int size = ls.size();

    for(int i=0; i<size; i++) {
        cout << ls[i] << " ";
    }

    // TC -> O(2N)
    // SC -> O(2) -> O(1)
return 0;
}