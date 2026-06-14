#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<
    int, 
    null_type, 
    less<int>, 
    rb_tree_tag, 
    tree_order_statistics_node_update
> ordered_set;
// We use the above syntax to extend the standard library of C++ to PBDS extension.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    int n,k;
    cin >> n >> k;
    ordered_set nums;
    for(int i=1; i<=n; i++) nums.insert(i);

    int pos=0;
    while(!nums.empty()) {
        pos = (pos+k)%(nums.size());
        auto it = nums.find_by_order(pos);
        cout << *it << " ";
        nums.erase(it);
    }
    cout << endl;
    // Simulation of the problem :-

    // n=7, k=2
    // Initially we have -> 1 2 3 4 5 6 7
    // We start at idx = 0, and since we first need to skip k elements and the array is cyclic, therefore we use this:-
    // pos = (pos+k)%len -> where pos stands for the current postion and len is the current length of the array.
    // print the element
    // remove the element but the position still remains same

    // pos = 0 (Initially), array -> 1 2 3 4 5 6 7
    // pos = (pos+k)%len = (0+2)%7 -> 2 remove 3 -> array becomes -> 1 2 4 5 6 7 (len = 6)
    // pos = (pos+k)%len = (2+2)%6 -> 4 remove 6 -> array becomes -> 1 2 4 5 7 (len = 5)
    // pos = (pos+k)%len = (4+2)%5 -> 1 remove 2 -> array becomes -> 1 4 5 7 (len = 4)
    // pos = (pos+k)%len = (1+2)%4 -> 3 remove 7 -> array becomes -> 1 4 5 (len = 3)
    // pos = (pos+k)%len = (3+2)%3 -> 2 remove 5 -> array becomes -> 1 4 (len = 2)
    // pos = (pos+k)%len = (2+2)%2 -> 0 remove 1 -> array becomes -> 4 (len = 1)
    // pos = (pos+k)%len = (0+2)%1 -> 0 remove 4 -> array becomes empty

    // order of print -> 3 6 2 7 5 1 4

    // Now when we analyze the problem we see that the elements of the array are initially sorted

    // We need to find the next guy to be removed = (pos+k)%len

    // Next remove the element efficiently.

    // For this we use a DS called Policy-Based Data structure (PBDS). This is a powerful extention to the standard library which is widely used for implementation of advanced features like Ordered Sets and Ordered Maps, allowing us to perform order-statistic operations with O(logn) TC.

    // Key Functionalities:- 
    // 1. find_by_order(k): Returns an iterator to the k-th element (0-indexed) in the set.
    // 2. order_of_key(x): Returns the number of elements strictly smaller than x.


    return 0;
}
