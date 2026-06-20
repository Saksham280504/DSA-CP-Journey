#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    // Here we need to find the smallest elements for all windows of size k and return the xor of all the smallest elements.
    
    // Brute way is to create all windows and find the minimum of all of them and then xor all of them to get the result -> O(n-k+1)*O(k)

    // Better way of solving this problem is to consider the window as a multiset which will hold the values of the window in sorted order. This will take a TC of O(nlogk) but since k<=n<=10^7, thus nlogk ~ 2.3*10^8 operations which will exceed 1s TC barrier.
    
    // For optimal approach, we will use the concept of deque which will store all the elements in ascending order so that we can peform the functions like getting minimum element of a window, insertion of an element in a window, deletion of an element from a window in constant time. Thus giving an overall TC of O(n)

    int n,k;
    cin >> n >> k;
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<ll> arr(n);
    for(int i=0; i<n; i++) {
        if(i==0) arr[i] = x;
        else arr[i] = ((a*arr[i-1])+b)%c;
    }
    deque<ll> dq;
    ll mini_xor = 0;

    int i=0; 
    for(int j=0; j<n; j++) { // i and j represents the left and right end of the window
        // Insertion
        while(!dq.empty() && dq.back()>arr[j]) dq.pop_back(); // The entering element will create dominance over already present elements in the window. If the elements in the window are greater than the entering element, then those elements are of no significance as they will never get the chance of becoming the smallest element of a window after this element become a part of the window, so remove them.
        dq.push_back(arr[j]);

        if(j-i+1<k) continue; // we let the size of window become k first
        else {
            mini_xor ^= dq.front();
            if(dq.front()==arr[i]) dq.pop_front();
            i++;
        }
    }

    cout << mini_xor << endl;

    return 0;
}
