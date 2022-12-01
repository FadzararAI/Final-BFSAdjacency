//Creates Menu Function
void menu(){
	bool exit = false;
	while(!exit){
		cout << "Input number of vertices: ";
		int vertices;
		cin >> vertices;
		
		//initialize the graph based on the number of vertices inputted 
		Graph g(vertices);
		
		cout << "Created graph with " << vertices << " vertices" << endl;
		
		bool reset = false;
		
		//create a pair to store adjacency lists with format [u,v]
		vector<pair <int, int> > lists;
		while(!reset){
			cout << "1. Insert adjacency list " << endl;
			cout << "2. View adjacency lists" << endl;
			cout << "3. Do BFS Traversal" << endl;
			cout << "4. Reset Graph" << endl;
			cout << "5. Exit Program" << endl;
			
			int chc;
			cin >> chc;
			if(chc == 1){
				int u,v;
				//Input list (index-1)
				cout << "Format [u,v]: ";
				cin >> u >> v;
				//Check if adjacency list already exists in the list
				for(int i = 0; i < lists.size() ; i++){
					if(u == lists[i].first && v == lists[i].second){
						cout  << "Adjecency list already exist!" << endl;
						continue;
					}
				}
				
				//Validate if user input is valid 
				if(validate(0, vertices-1, u) &&
				 	validate(0, vertices-1, v)){
					cout <<"Invalid input" << endl;
					continue;
				}
				//If the list is new and valid, insert to pair
				lists.push_back(make_pair(u, v));
				//and call addEdge function to insert edge to graph
				g.addEdge(u, v);
			}
			else if(chc == 2){}
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
		}
			
	}
}
