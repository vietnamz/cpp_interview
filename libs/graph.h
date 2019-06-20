#ifndef LIBS_GRAPH_H_
#define LIBS_GRAPH_H_

#include <vector>
#include <memory>
using namespace std; 
  
// Class to represent a graph 
class Graph { 
  
    // No. of vertices 
    size_t V;
  
    // Pointer to an array containing 
    // adjacency lists 
    std::unique_ptr<vector<int>[]> adj; 
  
    // A function used by NumOfNodes 
    void DFS(std::vector<bool>& visited, int src, int& curr_level, 
             int level, int& NumberOfNodes); 
  
public: 
    // Constructor 
    explicit Graph(int V); 
  
    // Function to add an edge to graph 
    void addEdge(int src, int des); 
  
    // Returns the no. of nodes 
    int NumOfNodes(int level); 
};  

#endif // LIBS_GRAPH_H_