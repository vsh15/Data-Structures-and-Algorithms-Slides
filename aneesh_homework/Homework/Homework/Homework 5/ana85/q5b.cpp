///////////////////////// Q5-b - BFS NewYork City Graph //////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
/////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<list>
#include<fstream>


using namespace std;


class graph
{
	int V;														// number of nodes
	vector<pair<int, float>> *adj;								// adjacency list

	

public:
	graph(int v);												// constructor

	void addEdge(int v, int w, float weight);
	
	void bfs(int start);
	void print();
};


graph::graph(int v)
{
	this->V = v;												// initialization
	this->adj = new vector<pair<int, float>>[V];
}


void graph::addEdge(int v, int w, float weight)
{
	adj[v].push_back(make_pair(w, weight));						// adding w to adjacency list of v 	
	adj[w].push_back(make_pair(v, weight));						// adding v to adjacency list of w		
}


void graph::print()												// print the graph
{
	for (int i = 0; i < V; i++)
	{
		cout << i << " -->";
		for (vector<pair<int, float>>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
		{
			cout << " node: " << it->first << " weight: " << it->second;
		}
		cout << endl;
	}
}



void graph::bfs(int s)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)									// Initialize vertices as not visited
		visited[i] = false;

	list<int> queue;											// BFS requires a queue

	visited[s] = true;											// Mark the current node as visited 
	queue.push_back(s);											// Push it in to the queue		


																//vector<pair<int, float>>::iterator i;

	while (!queue.empty())
	{
		s = queue.front();										// Pop a vertex from queue and print it
		cout << s << endl;

		queue.pop_front();


		for (vector<pair<int, float>>::iterator i = adj[s].begin(); i != adj[s].end(); ++i)		// for all adjacent vertices
		{
			if (!visited[i->first])								// if not visited
			{
				visited[i->first] = true;						// Mark as visited 
				queue.push_back(i->first);						// Push in to the queue
			}
		}
	}

}


int main(int argc, char* argv[])
{
	//////////////////// variables //////////////////
	int numNodes, numLinks;
	int src, dest;
	float weight;
	int firstNode = 0;
	/////////////////////////////////////////////////

	//////////////// input file access //////////////
	ifstream input_file(argv[1]);

	input_file >> numNodes;
	input_file >> numLinks;

	graph g(numNodes);							// create object of class graph

	int i = 0;
	while (!input_file.eof())
	{
		input_file >> src >> dest >> weight;
		g.addEdge(src, dest, weight);			// adding edges to graph
	}

	input_file.close();
	/////////////////////////////////////////////////


	cout << "Nodes Traversed in BFS exploration with starting node=0 : \n";
	g.bfs(firstNode);
	cout << endl;


	system("pause");
	return 0;
}