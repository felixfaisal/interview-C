## Directed Graph (DiGraph) 

## Weighed Graphs 
Edges contain certain weight 

## Special Graphs 
1. Trees - Undirected graph with no cycles 
2. Rooted Trees - A designated root node
3. Directed Acyclic Graphs - Directed graphs with no cycles
4. Bipartite graph - vertices can be split into independent groupds u and v
5. Complete Graph - A complete graph is one where there is a unique edge between every pair of nodes. 

## Adjacency Matrix

## Adjacency List

## Edge List

# Common Graph Theory Problems

## Shortest path problem
Given a weighted graph, find the shortest path of edges from node A to node B
- Does my weighted digraph have any negative cycles, if so, where? (Bellman-Ford & Floyd-Washall)
- Strongly Connected Componenets can be thought as self contained cycles within a directed graph where every vertex in a given cycle can reach every other vertex in the same cycle
- Travelling Salesman Problem (Held-Karp)
- Bridges 
- Articulation Points
- Minimum Spanning Tree (Kruskal;s, Prim's)
- Network flow - max flow (Ford-Fulkerson, Edmonds-Karp)

## Depth First Search 
It is the most fundamental algorithm used to explore nodes and edges of a graph, 
time complexity of O(V+E) and is often a building block in other algorithms

```
n = number of nodes in the graph 
g = adjacency list representing graph 
visited = [false..] #size n

function dfs(at):
    if visited[at]: return 
    visited[at] = true

    neighbours = graph[at];
    for next in neighbours: 
        dfs(next)

start_node = 0
dfs(start_node)
```
// Need to learn about list and map in C++

What else can DFS do?
1. Compute a graph's minimum spanning tree 
2. Detect and find cycles in a graph 
3. Check if a graph is bipartite 
4. Find strongly connected componnets 
5. Topologically sort the nodes of a graph
6. Find bridges and articulation points 
7. Generate mazes

## Breadth First Search 

```C++
// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include<iostream>
#include <list>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
	int V; // No. of vertices

	// Pointer to an array containing adjacency
	// lists
	list<int> *adj;
public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints BFS traversal from a given source s
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent
	// vertices of a vertex
	list<int>::iterator i;

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}

```

## Topological Sort
- Directed Acyclic Graph 
- Linear ordering of vertices 
- Every directed edge uv, for vertex u to v, u comes before v
```C++
// A C++ program to print topological sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
								stack<int>& Stack)
{
	// Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	// Push current vertex to stack which stores result
	Stack.push(v);
}

// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Graph::topologicalSort()
{
	stack<int> Stack;

	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Print contents of stack
	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given graph n";
	g.topologicalSort();

	return 0;
}
```

## Single Source Shortest Path Algorithm