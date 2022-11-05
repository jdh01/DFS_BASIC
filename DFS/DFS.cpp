#include <iostream>
#include <list>

class Graph {
private:
	//No. verticies
	int V;
	//Pointer to adjacency list
	std::list<int>* adj;
	//DFS recursive helper functions
	void DFS_helper(int s, bool* visited);
public:
	//Constructor prototype
	Graph(int v);
	//Method to add an edge
	void addEdge(int v, int w);
	//Method for BFS traveral from source 's'
	void DFS(int s);
};

//Constructor
Graph::Graph(int v) {
	//Setting no. verticies
	V = v;
	//Creating adjacency list for each vertex
	adj = new std::list<int>[v];
}

//Implemeting method to add edges
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::DFS_helper(int s, bool* visited) {
	//Mark the current node as visited
	std::cout << "Visited node " << s << std::endl;
	visited[s] = true;

	//Go through adjacency list
	for (auto i = adj[s].begin(); i != adj[s].end(); i++)
	{
		if (!visited[*i]) {
			std::cout << "Going to vertex " << *i << " from vertex " << s << std::endl;
			DFS_helper(*i, visited);
		}
	}
}

//Perform BFS
void Graph::DFS(int s) {
	//Start with all vertices as not visited
	bool* visited = new bool[V];
	for(int i = 0; i < V; i++){
		visited[i] = false;
	}
	//Beginning of recursive call
	DFS_helper(s, visited);
}

int main() {
	Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(0, 2);

	g.addEdge(1, 0);
	g.addEdge(1, 3);
	g.addEdge(1, 4);

	g.addEdge(2, 0);
	g.addEdge(2, 4);

	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 5);

	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 5);

	g.addEdge(5, 3);
	g.addEdge(5, 4);

	g.DFS(2);
}