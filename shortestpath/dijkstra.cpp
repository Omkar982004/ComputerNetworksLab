#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstras(int V, vector<vector<vector<int>>> &adj, int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                int v = it[0];
                int wt = it[1];
                if (dist + wt < distTo[v]) {
                    distTo[v] = dist + wt;
                    pq.push({distTo[v], v});
                }
            }
        }

        return distTo;
    }
};

int main() {
    int S, V, E;
    cin >> V >> E >> S;

    vector<vector<vector<int>>> adj(V); // Declare `adj` as a vector of vector<vector<int>>

    // Input edges
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // Since the graph is undirected
    }

    Solution obj;
    vector<int> distances = obj.dijkstras(V, adj, S);

    // Output the distances
    for (int i = 0; i < V; ++i) {
        cout << "Distance from source " << S << " to vertex " << i << " is: ";
        if (distances[i] == INT_MAX)
            cout << "INF";
        else
            cout << distances[i];
        cout << endl;
    }

    return 0;
}

/*
    sample input:
    5 6 0
    0 1 2
    0 2 4
    1 2 1
    1 3 7
    2 4 3
    3 4 1
 */
