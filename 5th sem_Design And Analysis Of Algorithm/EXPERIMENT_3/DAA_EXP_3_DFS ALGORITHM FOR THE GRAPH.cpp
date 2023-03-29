/*
AIM:
Write a program to implement the dfs algorithm for a graph.

Depth First Search Algorithm
A standard DFS implementation puts each vertex of the graph into one of two categories:
1. Visited
2. Not Visited
The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.
The DFS algorithm works as follows:
1. Start by putting any one of the graph's vertices on top of a stack.
2. Take the top item of the stack and add it to the visited list.
3. Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited 
list to the top of the stack.
4. Keep repeating steps 2 and 3 until the stack is empty.
Complexity Analysis: 
Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in 
the graph.
Space Complexity: O(V). 
Since an extra visited array is needed of size V.
*/
// Program:
 
#include <iostream>
#include <list>
using namespace std;
class Graph {
 int numVertices;
 list<int> *adjLists;
 bool *visited;
 public:
 Graph(int V);
 void addEdge(int src, int dest);
 void DFS(int vertex);
};// Initialize graph
Graph::Graph(int vertices) {
 numVertices = vertices;
 adjLists = new list<int>[vertices];
 visited = new bool[vertices];
}// Add edges
void Graph::addEdge(int src, int dest) {
 adjLists[src].push_front(dest);}// DFS algorithm
void Graph::DFS(int vertex) {
 visited[vertex] = true;
 list<int> adjList = adjLists[vertex];
 cout << vertex << " ";
 list<int>::iterator i;
 for (i = adjList.begin(); i != adjList.end(); ++i)
 if (!visited[*i])
 DFS(*i);
}int main() {
 Graph g(4);
 g.addEdge(0, 1);
 g.addEdge(0, 2);
 g.addEdge(1, 2);
 g.addEdge(2, 3);
 g.DFS(2);
 return 0;
}

