//////////////////////////// Q2-a - Prim's Algorithm /////////////////////////////////////
// Name - Aneesh Abhyankar
// RUID - 166006555
/////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>


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




void primAlgo(int V, vector<vector<float>> &adj)				// Code Reference : geeksforgeeks.com
{
	vector<int> parent(V, 0);
	vector<float> key(V, 20000.0);
	vector<bool> mstSet(V, false);

	key[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < V ; i++)
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
	cout << "MST formed using Prim's Algorithm : \n";
	output_file << "MST formed using Prim's Algorithm : \n";
	for (int i = 1; i < V; i++)
	{
		cout << parent[i] << " -- " << i << " == " << adj[i][parent[i]] << endl;
		output_file << parent[i] << " -- " << i << " == " << adj[i][parent[i]] << endl;
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
	int V;
	int numEdges, src, dest;
	float weight;

	
	ifstream file(argv[1]);

	file >> V;
	file >> numEdges;
	vector<vector<float>> adj(V, vector<float>(V));

	while (!file.eof())
	{
		file >> src >> dest >> weight;
		addEdge(adj, src, dest, weight);
	}
	file.close();
	
	clock_t start = clock();
	primAlgo(V, adj);
	clock_t end = clock();

	cout << "Execution Time : " << end - start << " ms" << endl;

	system("pause");
	return 0;
}