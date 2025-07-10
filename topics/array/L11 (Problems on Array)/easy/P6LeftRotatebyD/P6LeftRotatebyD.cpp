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

    cout << "Array before Left-Rotation: " << endl;

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int d;
    cin >> d;
    int rotationNum = d%arr.size();

    //My approach:
    // vector<int> tempArr;

    // for(int i=0; i<rotationNum; i++) {
    //     tempArr.push_back(arr[i]);
    // }
    
    // int j=0;
    // for(int i=0; i<n; i++) {
    //     if(i+rotationNum<n){
    //         arr[i] = arr[i+ rotationNum];
    //     }
    //     else {        
    //             arr[i] = tempArr[j];
    //             j++;
    //     }
    // }
    // TC -> O(N+rotationNum)
    // SC -> O(rotationNum)

    // cout << "Array after Left-Rotation: " << endl;

    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //Brute-force method:
    // vector<int> tempArr;

    // for(int i=0; i<rotationNum; i++) {
    //     tempArr.push_back(arr[i]);
    // }
    // int k=0;
    // for(int j=rotationNum; j<n; j++) {
    //     arr[j-rotationNum] = arr[j];
    // }

    // for(int j=n-rotationNum; j<n; j++) {
    //     arr[j] =tempArr[k];
    //     k++;
    // }

    // cout << "Array after Left-Rotation: " << endl;

    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl; 

    // TC -> O(N+rotationNum)
    // SC -> O(rotationNum)

    // My method-2 (better approach)
    // for(int i=0;i<rotationNum;i++){
    //     int temp = arr[0];
    //     for(int j=0;j<n-1;j++) {
    //         arr[j] = arr[j+1];
    //     }
    //     arr[n-1] = temp;
    // }
    // cout << "Array after Left-Rotation: " << endl;
    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl; 

    //TC-> O(d*N);
    //SC -> O(1);

    // Optimal Approach
    // reverse(arr.begin(), arr.begin() + rotationNum);
    // reverse(arr.begin()+ rotationNum, arr.end());
    // reverse(arr.begin(),arr.end());

    // cout << "Array after Left-Rotation: " << endl;
    // for(int i=0; i<n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //TC-> O(2N);
    //Sc-> O(1);


    // Code for Right rotation

    // My-approach-1
    // vector<int> tempArr;
    // for(int i=n-1; i>=rotationNum-1; i--) {
    //     tempArr.push_back(arr[i]);
    // }

    // int j=0;
    // for(int i=n-1; i>=0; i--) {
    //     if(i-rotationNum >= 0) {
    //         arr[i] = arr[i-rotationNum];
    //     }
    //     else {
    //         arr[i] = tempArr[j];
    //         j++;
    //     }
    // }

    // TC -> O(rotationNum + N)
    // SC -> O(rotationNum)

    //My-approach-2 (optimal approach)

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+ rotationNum);
    reverse(arr.begin()+rotationNum, arr.end());
    // TC -> O(2N)
    // SC -> O(1)

    cout << "Array after right-Rotation: " << endl;
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
