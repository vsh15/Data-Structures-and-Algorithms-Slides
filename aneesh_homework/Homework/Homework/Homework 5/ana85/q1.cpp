////////////////////////// Q1 - Check Cyclicity of Graph /////////////////////////////////
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
	
	bool cycleHelper(int v, bool visited[], int parent);		

public:
	graph(int v);												// constructor

	void addEdge(int v, int w, float weight);
	bool cycleExists();
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


bool graph::cycleHelper(int v, bool visited[], int parent)				// Code Reference : geeksforgeeks.com
{
	visited[v] = true;													// mark current node as visited 
	for (vector<pair<int, float>>::iterator it = adj[v].begin(); it != adj[v].end(); it++)		// for all neighbors
	{
		if (!visited[it->first])										// if not visited
		{
			if (cycleHelper(it->first, visited, v))						// call cycle helper recursively passing the neighbor and parent
				return true;
		}
		else if(it->first != parent)									// if the trace is not coming back from the parent
		{																// this means we assume that there are no parallel edges	
			return true;
		}
	}
	return false;
}


bool graph::cycleExists()
{
	bool *visited = new bool[V];			
	for (int i = 0; i < V; i++)	
	{
		visited[i] = false;								// initialize visited array by false. This initializes all nodes as unvisited
	}

	for (int j = 0; j < V; j++)
	{
		if (!visited[j])								// if not already visited
			if (cycleHelper(j, visited, -1))			// call cycle helper
				return true;
	}
	return false;
}


int main(int argc, char* argv[])
{
	//////////////////// variables //////////////////
	int numNodes, numLinks;			
	int src, dest;
	float weight;
	/////////////////////////////////////////////////
	
	//////////////// input file access //////////////
	ifstream file(argv[1]);
	
	file >> numNodes;
	file >> numLinks;

	graph g(numNodes);							// create object of class graph

	while (!file.eof())
	{
		file >> src >> dest >> weight;
		g.addEdge(src, dest, weight);			// adding edges to graph
	}

	file.close();
	/////////////////////////////////////////////////

	ofstream output_file("out.txt");

	if (g.cycleExists())						// call function to check for cyclicity
	{
		cout << "cycle exists" << endl;
		output_file << "cycle exists" << endl;
	}
	else
	{
		cout << "cycle does not exist" << endl;
		output_file << "cycle does not exist" << endl;
	}

	system("pause");
	return 0;
}

