//Vishalsingh Hajeri
//Data Structures and Analysis
//04/19/2016
//references:http://www.geeksforgeeks.org

#include<iostream>
#include<vector>
#include<fstream>

using namespace std;


int minKey(int V, vector<float> &key, vector<bool> &mstSet)
{
	float min = 20000.0;
	int minIndex;

	for (int i = 0; i < V; i++)
	{
		if (mstSet[i] == false && key[i] < min)
		{
			min = key[i];
			minIndex = i;
		}
	}
	return minIndex;
}




void prims_algorithm(int V, vector<vector<float>> &adj)
{
	vector<int> parent(V, 0);
	vector<float> key(V, 20000.0);
	vector<bool> mstSet(V, false);

	key[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < V; i++)
	{
		int min = minKey(V, key, mstSet);

		mstSet[min] = true;

		for (int j = 0; j < V; j++)
		{
			if (adj[min][j] != 0 && mstSet[j] == false && adj[min][j] < key[j])
			{
				parent[j] = min;
				key[j] = adj[min][j];
			}
		}
	}

	ofstream output_file("out.txt");
	cout << "Below are the nodes added to Minimum Spanning Tree";
	output_file << "MST : \n";
	for (int i = 1; i < V; i++)
	{
		cout << parent[i] << "-" << i << " = " << adj[i][parent[i]] << endl;
		output_file << parent[i] << "-" << i << "= " << adj[i][parent[i]] << endl;
	}
	output_file.close();
}


void addEdge(vector<vector<float>> &adj, int v, int w, float weight)
{
	adj[v][w] = weight;
	adj[w][v] = weight;
}


int main(int argc, char* argv[])
{
	int Vertexes;
	int Edges, edge1,edge2;
	double weight;


	ifstream file(argv[1]);

	file >> Vertexes;
	file >> Edges;
	vector<vector<float>> adj(Vertexes, vector<float>(Vertexes));

	while (!file.eof())
	{
		file >> edge1 >> edge2 >> weight;
		addEdge(adj, edge1, edge2, weight);
	}
	file.close();

	prims_algorithm(Vertexes, adj);


	return 0;
}