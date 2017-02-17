//Vishalsingh Hajeri
//Data Structures and Analysis
//04/19/2016
//references:http://www.geeksforgeeks.org

#include<iostream>
#include <list>
#include<fstream>
#include<string>
using namespace std;

// Class for an undirected graph
class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w);   // to add an edge to graph
	bool isCyclic();   // returns true if there is a cycle
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
	adj[w].push_back(v); // Add v to w’s list.
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
	
	visited[v] = true;

	
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		
		if (!visited[*i])
		{
			if (isCyclicUtil(*i, visited, v))
				return true;
		}

		else if (*i != parent)
			return true;
	}
	return false;
}


bool Graph::isCyclic()
{
	
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	
	for (int u = 0; u < V; u++)
		if (!visited[u]) 
			if (isCyclicUtil(u, visited, -1))
				return true;

	return false;
}


int main(int argc, char* argv[])

{
	string line;
	int vertexes=0;
	int edges;
	int edge1, edge2;
	
	double ignore;
	

	ifstream myfile;

	//read inputs from file
	myfile.open(argv[1]);

		myfile >> vertexes>>edges;
			cout << "Total Number of vertices: "<<vertexes<<endl;
		Graph g1(vertexes);

		while(!myfile.eof())
		{
			myfile >> edge1 >> edge2 >> ignore;

			g1.addEdge(edge1, edge2);
		//	cout << edge1 << " \t"<<edge2 << endl;
		}
		myfile.close();

		g1.isCyclic() ? cout << "Graph contains cycle\n" :
			cout << "Graph doesn't contain cycle\n";

	

	return 0;
}