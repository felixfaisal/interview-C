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

```C++
// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
	map<int, bool> visited;
	map<int, list<int>> adj;

	// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";
	g.DFS(2);

	return 0;
}

// improved by Vishnudev C

```

