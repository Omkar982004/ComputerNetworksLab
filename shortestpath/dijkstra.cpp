//Dijkstra using min heap

#include <bits/stdc++.h>
using namespace std;

/*
// bits/stdc++.h
// All the required standard libraries
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
*/

class Solution {
public:
    vector<int> dijkstras(int V, vector<vector<vector<int>>> &adj, int S) {

        //min heap declared {dist to reach destination ,destination from S}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //0 distance to reach first vertex S as it is the starting vertex
        //currently heap has only one element {0,S};
        pq.push({0, S});
        //vector to store the shortest distance from source to all other vertices
        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;

        //iterate while heap is not empty
        while (!pq.empty()) {
            //extract the vertex with minimum distance from S from the heap
            int node = pq.top().second;
            int dist = pq.top().first;
            //remove the vertex from the heap
            pq.pop();
            
            //iterate over all the adjacent vertices of the extracted vertex
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

sample output
Distance from source 0 to vertex 0 is: 0
Distance from source 0 to vertex 1 is: 2
Distance from source 0 to vertex 2 is: 3
Distance from source 0 to vertex 3 is: 7
Distance from source 0 to vertex 4 is: 6
 */


/*
Explanation:
The input for this code consists of:
The number of vertices V.
The number of edges E.
The source vertex S from which to calculate the shortest path.
For each edge, the two vertices it connects and the weight of the edge


Explanation of the function:
INPUT PARAMETERS
1.The vector<vector<vector<int>>> data structure is used to represent an adjacency list for a weighted graph, where each edge has a starting vertex, an ending vertex, and a weight. Here’s a breakdown of why it’s structured this way and how it works:
Structure Explanation
For a graph with V vertices:
vector<vector<vector<int>>> adj(V) creates an outer vector of size V, where each element corresponds to a vertex in the graph.
Each adj[u] is a vector<vector<int>>, which represents the list of all edges starting from vertex u.
Each element in adj[u] is a vector<int> of size 2, representing an edge:
adj[u][i][0] is the destination vertex v of the edge starting from u.
adj[u][i][1] is the weight of that edge.
2.no of vertices
3.starting vertex

OUTPUT
1.distance vector
*/


/*

TIME COMPLEXITY ANALYSIS
The min-heap (or priority queue in C++) is crucial for making Dijkstra's algorithm efficient by always allowing the algorithm to process the closest (or minimum distance) node next. This optimization ensures that each node is visited with the smallest possible path distance first, which avoids redundant work. Here’s a breakdown of how the min-heap achieves this:

Complexity Analysis
The use of the min-heap reduces the time complexity of Dijkstra’s algorithm:

Min-Heap Operations: Each insertion or extraction operation in the min-heap takes 
O(logV) time, where V is the number of vertices.
Edge Relaxation: For each edge, we perform a relaxation operation which might involve updating the min-heap. This results in 
O(ElogV) complexity, where E is the number of edges.
Thus, the overall time complexity of Dijkstra’s algorithm with a min-heap is:
O((V+E)logV)

Without a min-heap, the time complexity would be 
O(V^2) in an adjacency matrix . O(V⋅E) in an adjacency list, both of which are slower for dense or large graphs.

*/


/*
Space Complexity
When you sum all the space used by these data structures:

Adjacency list: 
O(V+E)
Distance array:
O(V)
Priority queue: 
O(V)
The overall space complexity is dominated by the adjacency list and is:
O(V+E)
*/