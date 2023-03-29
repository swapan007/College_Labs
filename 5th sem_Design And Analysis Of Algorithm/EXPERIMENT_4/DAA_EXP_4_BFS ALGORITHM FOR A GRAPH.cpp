/*
AIM:
Write a program to implement the bfs algorithm for a graph.

A standard BFS implementation puts each vertex of the graph into one of two categories:
• Visited
• Not Visited
The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.
The algorithm works as follows:
• Start by putting any one of the graph's vertices at the back of a queue.
• Take the front item of the queue and add it to the visited list.
• Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list 
to the back of the queue.
• Keep repeating steps 2 and 3 until the queue is empty.
BFS Algorithm Complexity
The time complexity of the BFS algorithm is represented in the form of O(V + E), where V is the 
number of nodes and E is the number of edges.
The space complexity of the algorithm is O(V).
BFS Algorithm Applications
• To build index by search index
• For GPS navigation
• Path finding algorithms
• In Ford-Fulkerson algorithm to find maximum flow in a network
• Cycle detection in an undirected graph
• In minimum spanning tree
*/
//Program:

// BFS algorithm in C++
#include <iostream>
#include <list>
using namespace std;
class Graph {
 int numVertices;
 list<int>* adjLists;
 bool* visited;
 public:
 Graph(int vertices);
 void addEdge(int src, int dest);
 void BFS(int startVertex);
};// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
 numVertices = vertices;
 adjLists = new list<int>[vertices];
}// Add edges to the graph
void Graph::addEdge(int src, int dest) {
 adjLists[src].push_back(dest);
 adjLists[dest].push_back(src);
}
// BFS algorithm
void Graph::BFS(int startVertex) {
 visited = new bool[numVertices];
 for (int i = 0; i < numVertices; i++)
 visited[i] = false;
 list<int> queue;
 visited[startVertex] = true;
 queue.push_back(startVertex);
 list<int>::iterator i;
 while (!queue.empty()) {
 int currVertex = queue.front();
 cout << "Visited " << currVertex << " ";
 queue.pop_front();
 for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
 int adjVertex = *i;
 if (!visited[adjVertex]) {
 visited[adjVertex] = true;
 queue.push_back(adjVertex);
 }
 }
 }
}
int main() {
 Graph g(4);
 g.addEdge(0, 1);
 g.addEdge(0, 2);
 g.addEdge(1, 2);
 g.addEdge(2, 0);
 g.addEdge(2, 3);
 g.addEdge(3, 3);
 g.BFS(2);
 return 0;
}

