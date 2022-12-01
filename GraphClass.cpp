class Graph{
	int numVertices;
	vector< vector<int> > adjList;
	
	public:
	Graph(int numVertices);
	void addEdge(int u, int v);
	void BFS(int src);
};

Graph::Graph(int numVertices){
	this->numVertices = numVertices;
	adjList.resize(numVertices);
}

void Graph::addEdge(int u, int v){
	adjList[u].pb(v);
}
