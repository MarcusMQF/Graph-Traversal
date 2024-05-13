#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Create a Adjacency List representation of a graph
vector<vector<int>> graph = {{1}, {4}, {4,5,6}, {4}, {1,2,3}, {2}, {2,7}, {6}};

//Function to perform DFS
void DFS(int start){
    // This is a boolean vector used to keep track of which nodes have been visited during the Depth-First Search (DFS) traversal
    // It is initialized with false values for all nodes, indicating that initially, no node has been visited
    vector<bool> visited(graph.size(), false);
    stack<int> stack; // Create a stack (data structure) for DFS

    stack.push(start); // Push the starting node onto the stack

    while(!stack.empty()){
        int current = stack.top();  // Get the top node from the stack
        stack.pop();  // Remove the current/top node from the stack

        if(!visited[current]){
            visited[current] = true;
            cout << current << " ";

            // Push all unvisited neighbors of the current node onto the stack
            for(int neighbour: graph[current]){
                if(!visited[neighbour]){
                    stack.push(neighbour);
                }
            }
        }
    }
}

int main(){
    int startnode = 0; // Choose the starting node
    cout << "DFS (Death First Search) Traversal: ";
    DFS(startnode);

    cout << endl;

    return 0;
}

