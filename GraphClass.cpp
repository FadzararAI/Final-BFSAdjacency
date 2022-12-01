#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Graph{
	int numVertices;
	vector< vector<int> > adjList;
	
	public:
	//graph constructor
	Graph(int numVertices);
	//graph functions
	void addEdge(int u, int v);
	void BFS(int src);
};

//constructor
Graph::Graph(int numVertices){
	this->numVertices = numVertices;
	adjList.resize(numVertices);
}

//function to add edge
void Graph::addEdge(int u, int v){
	adjList[u].pb(v);
}
