
// Problem Statement: Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertices from the source vertex S.

// Note: If the Graph contains a negative cycle then return an array consisting of only -1.

// Input Format: 
// V = 6, 
// E = [[3, 2, 6], [5, 3, 1], [0, 1, 5], [1, 5, -3], [1, 2, -2], [3, 4, -2], [2, 4, 3]], 
// S = 0
// Result: 0 5 3 3 1 2
// Explanation: Shortest distance of all nodes from the source node is returned.

#include <bits/stdc++.h>
/*
#include<vector>
#include<iostream>
*/
using namespace std;

class Solution {
public:
	/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector<int> dist(V, 1e8);
		dist[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}


		return dist;
	}
};


int main() {
    // Input: number of vertices
    int V;
    cin >> V;

    // Input: number of edges
    int E;
    cin >> E;

    // Input: source vertex
    int S;
    cin >> S;

    // Input: edges, each edge has a source, destination and weight
    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];  // u, v, wt
    }

    Solution obj;
    vector<int> dist = obj.bellman_ford(V, edges, S);

    // Output: Shortest distances from source S
    for (auto d : dist) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}

/*
explanation : https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/
*/