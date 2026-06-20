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
    int n;
    cin >> n;
    vector<pair<ll,ll>> tasks(n);
    for(int i=0; i<n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    ll reward = 0;
    ll totalTime = 0;
    for(int i=0; i<n; i++) {
        totalTime += tasks[i].first;
        reward += (tasks[i].second - totalTime);
    }

    cout << reward << endl;

    // Doing smaller duration tasks first will decrease their finishing time by larger extent than it would increase the finishing time of larger duration tasks and since deadlines are constant, the overall sum of reward will increase.

    // For eg:- (___________a-duration task____________)(____b-duration task____)
    //          (____b-duration task____)(___________a-duration task____________) -> as you can see the finishing time of b-duration task reduced by a-duration task length, while the finishing time of a-duration task increased by only b-duration task time.

    // Thi means -> initially reward was -> (da-a) + (db-(a+b))
    // After swapping -> reward becomes -> (db-(a+b-a)) + (da-(a+b)) -> (db-b) + (da-(a+b)) -> (2) > (1)
    return 0;
}
