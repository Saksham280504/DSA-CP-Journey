#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

// This will not work because sorting may cause the larger tasks that could have been clubbed earlier with smaller tasks to occupy one sessionTime efficiently, would now be used inefficiently causing extra sessions being used unnecessarily.
// class Solution {
// public:
//     int minSessions(vector<int>& tasks, int sessionTime) {
//         sort(tasks.begin(), tasks.end());
//         int sum = 0;
//         int cnt = 0;
//         for(int i=0; i<tasks.size(); i++) {
//             sum += tasks[i];
//             if(sum>sessionTime) {
//                 cnt++;
//                 sum = tasks[i];
//             }
//         }
//         cnt++;

//         return cnt;
//     }
// };

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code here

    return 0;
}
