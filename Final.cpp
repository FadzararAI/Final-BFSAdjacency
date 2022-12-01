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

//function to add edge to graph
void Graph::addEdge(int u, int v){
	adjList[u].pb(v);
}

void Graph::BFS(int src){
	//initialize all nodes as unvisited
	vector<bool> visited(numVertices, false);
	
	//initialize queue for bfs
	queue<int> q;
	
	//mark src node as visited and push to queue
	visited[src] = true;
	q.push(src);
	
	//loop until queue is empty
	while(!q.empty()){
		int temp = q.front();
		//print the visited nodes
		cout << "Visited: " << temp << endl;
		q.pop();
		
		//traverse adjlist
		for(int i = 0; i < adjList[temp].size(); i++){
			int v = adjList[temp][i];
			//if not yet visited
			if(!visited[v]){
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

//helper function to help validate input
bool validate(int a, int b, int x){
	if(a >= x && x <= b) return true;
	return false;
}

//menu function
void menu(){
	bool exit = false;
	while(!exit){
		cout << "Input number of vertices: ";
		int vertices;
		cin >> vertices;
		
		//initialize graph based on number of vertices inputted
		Graph g(vertices);
		
		cout << "Created graph with " << vertices << " vertices" << endl;
		
		bool reset = false;
		//creating a pair to store adjacency lists
		vector<pair <int, int> > lists;
		while(!reset){
			cout << "1. Insert adjacency list " << endl;
			cout << "2. View adjacency lists" << endl;
			cout << "3. Do BFS Traversal" << endl;
			cout << "4. Reset Graph" << endl;
			cout << "5. Exit Program" << endl << endl;
			
			int chc;
			cout << "Input Your Option: ";
			cin >> chc;
			
			if(chc == 1){
				int u,v;
				//input list (index-1)
				cout << "Format [u v]: ";
				cin >> u >> v;
				
				//check if adjacency list already exists in the list
				for(int i = 0; i < lists.size() ; i++){
					if(u == lists[i].first && v == lists[i].second){
						cout  << "Adjecency list already exist!" << endl;
						continue;
					}
				}
				
				//validate if user input is valid 
				if(validate(0, vertices-1, u) &&
				 	validate(0, vertices-1, v)){
					cout <<"Invalid input" << endl;
					continue;
				}
				
				//if list is new and valid, insert to pair
				lists.push_back(make_pair(u, v));
				//and call addEdge function to insert edge to graph
				g.addEdge(u, v);
			}
			else if(chc == 2){
				cout << "Adjecency lists: " << endl;
				//print all the inputted lists
				for(int i = 0; i < lists.size(); i++){
					cout << lists[i].first << " " << lists[i].second << endl;
				}
			}
			else if(chc == 3){
				cout << "Choose starting node: " << endl;
				int src;
				cin >> src;
				//call BFS function with src parameter as startign node
				g.BFS(src);
				cout << "Graph traversal success!" << endl;
			}
			else if(chc == 4){
				//stops inner loop
				reset = true;
				break;
			}
			else if(chc == 5){
				//stops both inner and outer loop
				reset = true;
				exit = true;
				break;
			}
			else{
				//invalid inputs goes here
				continue;
			}
			
		}
	}
}

int main(){
	
	menu();
	
	return 0;
}
