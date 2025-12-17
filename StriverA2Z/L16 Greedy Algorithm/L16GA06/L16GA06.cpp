#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

class Meeting { // I have created a data structure to store the start time, end time and position of every Meeting
    public:
    int start;
    int end;
    int position;
};
class Solution {
    private:
    static bool comp(const Meeting& meet1,const Meeting& meet2) { // const makes sure that comparator doesn't modify the operands, and we use Meeting& rather than Meeting because we don't want extra space to be created everytime the comparator function is called 
        if(meet1.end!=meet2.end) return meet1.end<meet2.end;
        return meet1.position < meet2.position;
    }
    public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        // 1. Creation of data structure for holding the information (startTime, endTime, position) of every meeting
        vector<Meeting> arr(n);
        for(int i=0; i<n; i++) {
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].position = i+1;
        }

        // 2. Perform sort on arr in terms of endTime
        sort(arr.begin(),arr.end(),comp);

        int cnt =  1; // Atleast one meeting will be scheduled
        int freeTime = arr[0].end;
        vector<int> posOfMeets;
        posOfMeets.push_back(arr[0].position);
        
        for(int i=1; i<n; i++) {
            if(arr[i].start>freeTime) {
                cnt++;
                freeTime = arr[i].end;
                posOfMeets.push_back(arr[i].position);
            }
        }

        return cnt;
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
