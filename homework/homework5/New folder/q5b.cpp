//Vishalsingh Hajeri
//Data Structures and Analysis
//04/19/2016
//references:http://www.geeksforgeeks.org


#include<iostream>
#include <list>
#include<fstream>
using namespace std;

class Graph
{
	int V;    
	list<int> *adj;    
public:
	Graph(int V);  
	void addEdge(int v, int w); 
	void BFS(int s);  
};



Graph::Graph(int V) //Define constructor Graph
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) 
{
	adj[v].push_back(w); 
}




void Graph::BFS(int s) //Define function BFS
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	list<int>::iterator i;
	ofstream outfile;
	outfile.open("out.txt", ios::out);
	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		//print results to file
		outfile << s << " " << endl;
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}





int main(int argc, char* argv[])
{
	
	int v, e, a, b, c, d;
	ifstream myfile;
	myfile.open(argv[1]);
	myfile >> v >> e;
	
	Graph g(v);
	for (int i = 0; i < e; i++)
	{
		myfile >> a >> b >> c;

		g.addEdge(a, b); 
	}
	cout << "\nEnter the vertex from where the BFS has to be performed";
	cin >> d;
	g.BFS(d); 

	cout << "\nResults printed to out.txt";
	system("pause");
	return 0;
}