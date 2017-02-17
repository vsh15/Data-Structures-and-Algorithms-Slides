//Vishalsingh Hajeri
//Data Structures and Analysis
//04/19/2016
//references:http://www.geeksforgeeks.org


#include<iostream>
#include<vector>
#include<list>
#include<fstream>


using namespace std;


class graph
{
	int V;														// number of nodes
	vector<pair<int, float>> *adj;								// adjacency list

	void dfsHelper(int v, bool visited[]);

public:
	graph(int v);												// constructor

	void addEdge(int v, int w, float weight);
	void dfs(int start);
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


void graph::dfsHelper(int v, bool visited[])
{
	visited[v] = true;											// Mark the current node as visited and print it 

	cout << v << endl;

	for (vector<pair<int, float>>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)			// for all adjacent vertices
	{
		if (!visited[it->first])								// if not visited
		{
			dfsHelper(it->first, visited);						
		}
	}
}


void graph::dfs(int start)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)									
		visited[i] = false;

	dfsHelper(start, visited);									
}




int main(int argc, char* argv[])
{
	
	int numNodes, numLinks;
	int src, dest;
	float weight;
	int firstNode = 0;
	
	ifstream file(argv[1]);

	file >> numNodes;
	file >> numLinks;

	graph g(numNodes);							

	int i = 0;
	while (!file.eof())
	{
		file >> src >> dest >> weight;
		g.addEdge(src, dest, weight);			
		cout << src << dest;
	}

	file.close();
	
	cout << "Nodes Traversed in DFS exploration with starting node = 0 : \n";
	g.dfs(firstNode);
	cout << endl;


	system("pause");
	return 0;
}