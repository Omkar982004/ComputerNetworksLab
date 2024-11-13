#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Initialize matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;  // Use a large number to represent infinity
                }
                if (i == j) matrix[i][j] = 0;  // Distance from a vertex to itself is 0
            }
        }

        // Floyd-Warshall algorithm to compute shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // Negative cycle detection
        for (int i = 0; i < n; i++) {
            if (matrix[i][i] < 0) {
                // If matrix[i][i] is negative, there is a negative cycle
                cout << "Negative cycle detected!" << endl;
                return;  // Exit the function
            }
        }

        // Replace large values with -1 (for unreachable nodes)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;  // Indicate unreachable vertices
                }
            }
        }

        // Print the shortest distance matrix
        for (auto row : matrix) {
            for (auto cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1));

    // Create a graph with edges and weights
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    // Add a negative cycle for testing
    matrix[2][1] = -6;  // This creates a negative cycle: 2 -> 1 -> 3 -> 2

    Solution obj;
    obj.shortest_distance(matrix);

    return 0;
}

/*
resource - https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/
*/