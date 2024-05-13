#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph representation as an adjacency list
vector<vector<int>> graph = {{1}, {4}, {4, 5, 6}, {4}, {1, 2, 3}, {2}, {2, 7}, {6}};

// Function to perform BFS traversal
void BFS(int start) {
    vector<bool> visited(graph.size(), false); // Initialize a visited vector
    queue<int> queue; // Create a queue for BFS

    visited[start] = true; // Mark the starting node as visited
    queue.push(start); // Enqueue the starting node

    while (!queue.empty()) {
        int current = queue.front(); // Dequeue the front node
        queue.pop();
        cout << current << " "; // Process the current node (in this case, print it)

        // Enqueue all unvisited neighbors of the current node
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark the neighbor as visited
                queue.push(neighbor); // Enqueue the neighbor
            }
        }
    }
}

int main() {
    int startNode = 0;

    cout << "BFS (Breathed First Search) traversal: ";
    BFS(startNode);
    cout << endl;

    return 0;
}

