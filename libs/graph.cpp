#include "graph.h"
#include <vector>
#include <memory>

using namespace std;
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = std::make_unique<vector<int>[]>(V);
} 
  
void Graph::addEdge(int src, int des) 
{ 
    adj[src].push_back(des); 
    adj[des].push_back(src); 
} 
  
// DFS function to keep track of 
// number of nodes 
void Graph::DFS(vector<bool>& visited, int src, int& curr_level, 
                int level, int& NumberOfNodes) 
{ 
    // Mark the current vertex as visited 
    visited[src] = true; 
  
    // If current level is equal 
    // to the given level, increment 
    // the no. of nodes 
    if (level == curr_level) { 
        NumberOfNodes++; 
    } 
    else if (level < curr_level) 
        return; 
    else { 
        vector<int>::iterator i; 
  
        // Recur for the vertices 
        // adjacent to the current vertex 
        for (i = adj[src].begin(); i != adj[src].end(); i++) { 
            if (!visited[*i]) { 
                curr_level++; 
                DFS(visited, *i, curr_level, level, NumberOfNodes); 
            } 
        } 
    } 
    curr_level--; 
} 
  
// Function to return the number of nodes 
int Graph::NumOfNodes(int level) 
{ 
    // To keep track of current level 
    int curr_level = 0; 
  
    // For keeping track of visited 
    // nodes in DFS 
    vector<bool> visited(V, false); 
  
    // To store count of nodes at a 
    // given level 
    int NumberOfNodes = 0; 
  
    DFS(visited, 0, curr_level, level, NumberOfNodes); 
  
    return NumberOfNodes; 
} 