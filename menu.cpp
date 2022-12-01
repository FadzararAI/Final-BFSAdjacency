//Creates Menu Function
void menu(){
	bool exit = false;
	while(!exit){
		cout << "Input number of vertices: ";
		int vertices;
		cin >> vertices;
		while(!reset){
			cout << "1. Insert adjacency list " << endl;
			cout << "2. View adjacency lists" << endl;
			cout << "3. Do BFS Traversal" << endl;
			cout << "4. Reset Graph" << endl;
			cout << "5. Exit Program" << endl;
			
			int chc;
			cin >> chc;
			if(chc == 1){}
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
