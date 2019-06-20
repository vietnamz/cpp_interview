#include "gtest/gtest.h"
#include "libs/graph.h"
#include <string>

using namespace std;

TEST(GraphTest, firstTest) {
    Graph g(8); 
    g.addEdge(0, 1); 
    g.addEdge(0, 4); 
    g.addEdge(0, 7); 
    g.addEdge(4, 6); 
    g.addEdge(4, 5); 
    g.addEdge(4, 2); 
    g.addEdge(7, 3); 
  
    int level = 2; 
    EXPECT_EQ(g.NumOfNodes(level), 4);
}


