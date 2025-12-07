#include <bits/stdc++.h>
using namespace std;
// #define int long long  => when use this convert int main()  to int32_t main()
// #define endl '/n'

vector<int> dijkstra1(int n, vector<vector<int>> adjLS[], int src) {
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // We have taken a min_heap whose each element is of the form {dis,node}. Min_Heap will always have the minimum entry on top.
    vector<int> dist(n,1e9);
    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adjLS[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis+edgeWeight<dist[adjNode]) {
                dist[adjNode] = edgeWeight+dis;
                pq.push({dist[adjNode],adjNode});
            }
        }

        return dist;
    }

    // Why does dijkstra's algorithm not work on negative weight cycle?

    // Any graph with negative weights will not follow dijkstra's algorithm as it will fall in an infinite loop.

    // TC -> O(ElogV)
    // E -> Number of Edges
    // V -> Number of Nodes
}

vector<int> dijkstra2(int n, vector<vector<int>> adjLS[], int src) {
    set<pair<int,int>> st;
    vector<int> dist(n,1e9);
    dist[src] = 0;

    st.insert({0,src});

    while(!st.empty()) {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;

        for(auto adj: adjLS[node]) {
            int adjNode = adj[0];
            int edgeWeight = adj[1];
            if(dis+edgeWeight<dist[adjNode]) {
                if(dist[adjNode]!=1e9) {
                    st.erase({dist[adjNode],adjNode}); // Set differs from priority queue because it provides us the facility to erase. This does reduce some TC but it is very little and it is also not certain that even if we do find a better distance for a node than before, then we will have an entry as {Older distance, node} still present in the queue, but still we will look for it which will cause some extra effort. Thus in the end, whether you are able to delete an entry or not does't create much of a difference on the TC. Therefore, using priority_queue or set is both somewhere the same.
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }

    return dist;

}

vector<int> dijkstra3() {

    // Why priority queue and not queue?
    // We use priority queue rather than queue, because even though using a queue will give us an answer, we see that queue follows FIFO mechanism whereas in priority queue we saw that the top position is for the entry with the minimum value. So using queue mechanism leads to occurance of unnecessary steps and thus increase of TC happens. This doesn't happen in priority_queue because there the priority is given to the minimum entry.
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

    // Dijkstra's Algorithm

    // We will be given a weighted, undirected/directed graph with n nodes (0,n-1).
    // Dijkstra's algorithm is applicable through 3 ways: 1) queue (worst) 2) Priority_queue (better) 3) set (best)
    
    // First we will try it using priority_queue, and then set
    return 0;
}
